import socket
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.exceptions import InvalidTag, InvalidSignature

def load_keys():
    """Loads Bob's private identity key and Alice's public identity key."""
    with open("bob_private.pem", "rb") as f:
        bob_priv = serialization.load_pem_private_key(f.read(), password=None)
    with open("alice_public.pem", "rb") as f:
        alice_pub = serialization.load_pem_public_key(f.read())
    return bob_priv, alice_pub

def start_server():
    host, port = '0.0.0.0', 65432
    bob_identity_priv, alice_identity_pub = load_keys()
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((host, port))
        s.listen()
        print(f"[*] Bob (Server) listening on {host}:{port}...")
        
        conn, addr = s.accept()
        with conn:
            print(f"[*] Connection established from {addr}")

            try:
                # --- PHASE 1: AUTHENTICATED ECDH HANDSHAKE ---
                # TODO: 1. Generate Bob's ephemeral X25519PrivateKey
                bob_private_key = x25519.X25519PrivateKey.generate()

                # TODO: 2. Extract Bob's X25519 public bytes
                bob_public_bytes = bob_private_key.public_key().public_bytes(
                    encoding=Encoding.Raw,
                    format=PublicFormat.Raw,
                )
                
                # TODO: 3. Use bob_identity_priv to SIGN the X25519 public bytes using padding.PSS and hashes.SHA256()
                signature = bob_identity_priv.sign(
                    bob_public_bytes,
                    padding.PSS(
                        mgf=padding.MGF1(hashes.SHA256()),
                        salt_length=padding.PSS.MAX_LENGTH
                    ),
                    hashes.SHA256()
                )
                
                # TODO: 4. Receive Alice's data (Format: 256-byte signature + 32-byte X25519 public key)
                alice_data = recv_exact(conn, 288)
                alice_signature = alice_data[:256]
                alice_public_bytes = alice_data[256:]

                # TODO: 5. Use alice_identity_pub to VERIFY Alice's signature against her X25519 public bytes.
                #          (If verification fails, cryptography will raise an InvalidSignature exception. Let it crash the connection.)
                alice_identity_pub.verify(
                    alice_signature,
                    alice_public_bytes,
                    padding.PSS(
                        mgf=padding.MGF1(hashes.SHA256()),
                        salt_length=padding.PSS.MAX_LENGTH
                    ),
                    hashes.SHA256()
                )

                # TODO: 6. Send Bob's signature and Bob's X25519 public bytes to Alice.
                conn.sendall(signature + bob_public_bytes)

                # TODO: 7. Compute the shared_secret using the verified X25519 points.
                shared_secret = bob_private_key.exchange(
                    x25519.X25519PublicKey.from_public_bytes(alice_public_bytes)
                )

                # --- PHASE 2: KEY DERIVATION ---
                # TODO: Derive the AES key using HKDF (Same as Week 2)
                aes_key = derive_aes_key(shared_secret)
                
                # --- PHASE 3: RECEIVE PAYLOAD ---
                # TODO: Receive and decrypt the AES-GCM payload (Same as Week 1 & 2)
                chunks = []
                while True:
                        chunk = conn.recv(4096)
                        if not chunk:
                            break
                        chunks.append(chunk)
                data = b"".join(chunks)

                if not data:
                    print("[-] No payload data received.")
                    return

                if data:
                        # TODO: Extract nonce, tag, and ciphertext.
                        # TODO: Call your Week 1 decrypt_payload() using the NEW derived key.
                        if len(data) < 28:
                            print("[-] Payload too short to contain nonce + tag + ciphertext.")
                            return

                        nonce = data[:12]
                        tag = data[12:28]
                        ciphertext = data[28:]

                        try:
                            plaintext = decrypt_payload(nonce, ciphertext, tag, aes_key)
                            print("[*] Payload decrypted successfully.")
                            print(f"[*] Decrypted plaintext: {plaintext.decode()}")
                        except InvalidTag:
                            print("[-] Decryption failed. Invalid authentication tag. Possible tampering detected.")
                        except UnicodeDecodeError:
                            print("[-] Decryption succeeded, but plaintext is not valid UTF-8.")
            except ConnectionError as e:
                print(f"[-] Handshake failed: {e}")
            except ValueError as e:
                print(f"[-] Handshake failed: {e}")
            except InvalidSignature:
                print("[-] Handshake failed: Invalid signature. Authentication failed.")
            

if __name__ == "__main__":
    start_server()