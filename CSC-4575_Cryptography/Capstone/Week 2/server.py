import socket
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.serialization import Encoding, PublicFormat
from cryptography.exceptions import InvalidTag


def decrypt_payload(nonce: bytes, ciphertext: bytes, tag: bytes, key: bytes) -> bytes:
    cipher = Cipher(algorithms.AES(key), modes.GCM(nonce, tag))
    decryptor = cipher.decryptor()
    plaintext = decryptor.update(ciphertext) + decryptor.finalize()
    return plaintext


def recv_exact(sock: socket.socket, size: int) -> bytes:
    data = b""
    while len(data) < size:
        chunk = sock.recv(size - len(data))
        if not chunk:
            raise ConnectionError("Connection closed before receiving expected data.")
        data += chunk
    return data

def derive_aes_key(shared_secret: bytes) -> bytes:
    """
    TODO: Implement HKDF to derive a 32-byte AES key.
    Use SHA256 as the algorithm, length=32, salt=None, info=b'handshake data'.
    """
    hkdf = HKDF(
        algorithm=hashes.SHA256(),
        length=32,
        salt=None,
        info=b"handshake data",
    )
    return hkdf.derive(shared_secret)

def start_server():
    host, port = '0.0.0.0', 65432
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Allow immediate reuse of the port to prevent "Address already in use" errors
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((host, port))
        s.listen()
        print(f"[*] Bob (Server) listening on {host}:{port}...")
        
        conn, addr = s.accept()
        with conn:
            print(f"[*] Connection established from {addr}")
            
            # --- PHASE 1: ECDH HANDSHAKE ---
            # TODO: 1. Generate Bob's X25519PrivateKey
            # TODO: 2. Receive Alice's 32-byte public key over 'conn'
            # TODO: 3. Reconstruct Alice's public key object from the raw bytes
            # TODO: 4. Send Bob's public key (raw bytes) to Alice over 'conn'
            # TODO: 5. Compute the shared_secret using bob_private_key.exchange()
            bob_private_key = x25519.X25519PrivateKey.generate()

            alice_public_bytes = recv_exact(conn, 32)
            alice_public_key = x25519.X25519PublicKey.from_public_bytes(alice_public_bytes)

            bob_public_bytes = bob_private_key.public_key().public_bytes(
                encoding=Encoding.Raw,
                format=PublicFormat.Raw,
            )
            conn.sendall(bob_public_bytes)
            shared_secret = bob_private_key.exchange(alice_public_key)
            
            # --- PHASE 2: KEY DERIVATION ---
            # TODO: Derive the AES key by calling derive_aes_key(shared_secret)
            aes_key = derive_aes_key(shared_secret)
            
            # --- PHASE 3: RECEIVE PAYLOAD ---
            data = conn.recv(4096)
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
            else:
                print("[-] No payload data received.")

if __name__ == "__main__":
    start_server()