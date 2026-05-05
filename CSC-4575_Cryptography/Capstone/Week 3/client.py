import socket
import os
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.serialization import Encoding, PublicFormat
from cryptography.exceptions import InvalidSignature

def load_keys():
    """Loads Alice's private identity key and Bob's public identity key."""
    with open("alice_private.pem", "rb") as f:
        alice_priv = serialization.load_pem_private_key(f.read(), password=None)
    with open("bob_public.pem", "rb") as f:
        bob_pub = serialization.load_pem_public_key(f.read())
    return alice_priv, bob_pub

def encrypt_payload(plaintext: bytes, key: bytes) -> tuple[bytes, bytes, bytes]:
    nonce = os.urandom(12)
    cipher = Cipher(algorithms.AES(key), modes.GCM(nonce))
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(plaintext) + encryptor.finalize()
    tag = encryptor.tag
    return (nonce, ciphertext, tag)


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
    DONE: Implement HKDF to derive a 32-byte AES key.
    Must match the Server's HKDF parameters exactly.
    """
    hkdf = HKDF(
        algorithm=hashes.SHA256(),
        length=32,
        salt=None,
        info=b"handshake data",
    )
    return hkdf.derive(shared_secret)

def start_client():
    host, port = 'bob_node', 65432
    message = b"CLASSIFIED: The Eagle flies at midnight."
    alice_identity_priv, bob_identity_pub = load_keys()
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.connect((host, port))
            print(f"[*] Connected to Bob at {host}:{port}")
            
            # --- PHASE 1: AUTHENTICATED ECDH HANDSHAKE ---
            # DONE: 1. Generate Alice's ephemeral X25519PrivateKey
            alice_private_key = x25519.X25519PrivateKey.generate()

            # DONE: 2. Extract Alice's X25519 public bytes
            alice_public_bytes = alice_private_key.public_key().public_bytes(
                encoding=Encoding.Raw,
                format=PublicFormat.Raw,
            )
            
            # DONE: 3. Use alice_identity_priv to SIGN the X25519 public bytes using padding.PSS and hashes.SHA256()
            signature = alice_identity_priv.sign(
                alice_public_bytes,
                padding.PSS(
                    mgf=padding.MGF1(hashes.SHA256()),
                    salt_length=padding.PSS.MAX_LENGTH
                ),
                hashes.SHA256()
            )
            
            # DONE: 4. Send Alice's signature (256 bytes) and Alice's X25519 public key (32 bytes) to Bob.
            s.sendall(signature + alice_public_bytes)
            
            # DONE: 5. Receive Bob's data (Format: 256-byte signature + 32-byte X25519 public key)
            bob_data = recv_exact(s, 288)
            bob_signature = bob_data[:256]
            bob_public_bytes = bob_data[256:]

            # DONE: 6. Use bob_identity_pub to VERIFY Bob's signature against his X25519 public bytes.
            bob_identity_pub.verify(
                bob_signature,
                bob_public_bytes,
                padding.PSS(
                    mgf=padding.MGF1(hashes.SHA256()),
                    salt_length=padding.PSS.MAX_LENGTH
                ),
                hashes.SHA256()
            )
            
            # DONE: 7. Compute the shared_secret using the verified X25519 points.
            shared_secret = alice_private_key.exchange(
                x25519.X25519PublicKey.from_public_bytes(bob_public_bytes)
            )

            # --- PHASE 2: KEY DERIVATION ---
            # DONE: Derive the AES key using HKDF (Same as Week 2)
            aes_key = derive_aes_key(shared_secret)
            
            # --- PHASE 3: SECURE PAYLOAD ---
            # DONE: Encrypt and send the AES-GCM payload (Same as Week 1 & 2)
            nonce, ciphertext, tag = encrypt_payload(message, aes_key)
            s.sendall(nonce + tag + ciphertext)
            
        except ConnectionRefusedError:
            print("[-] Connection refused. Is Bob's server running?")
        except ConnectionError as e:
            print(f"[-] Handshake failed: {e}")
        except InvalidSignature:
            print("[-] Handshake failed: Invalid signature from Bob. Authentication failed.")
        except ValueError as e:
            print(f"[-] Invalid peer public key or cryptographic parameters: {e}")

if __name__ == "__main__":
    start_client()