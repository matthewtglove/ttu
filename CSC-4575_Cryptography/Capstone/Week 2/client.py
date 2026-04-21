import socket
import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.serialization import Encoding, PublicFormat


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
    TODO: Implement HKDF to derive a 32-byte AES key.
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
    # Docker automatically resolves container names to internal IPs
    host, port = 'bob_node', 65432
    message = b"CLASSIFIED: The Eagle flies at midnight."
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.connect((host, port))
            print(f"[*] Connected to Bob at {host}:{port}")
            
            # --- PHASE 1: ECDH HANDSHAKE ---
            # TODO: 1. Generate Alice's X25519PrivateKey
            # TODO: 2. Send Alice's public key (raw bytes) to Bob over 's'
            # TODO: 3. Receive Bob's 32-byte public key over 's'
            # TODO: 4. Reconstruct Bob's public key object from the raw bytes
            # TODO: 5. Compute the shared_secret using alice_private_key.exchange()
            alice_private_key = x25519.X25519PrivateKey.generate()
            alice_public_bytes = alice_private_key.public_key().public_bytes(
                encoding=Encoding.Raw,
                format=PublicFormat.Raw,
            )
            s.sendall(alice_public_bytes)

            bob_public_bytes = recv_exact(s, 32)
            bob_public_key = x25519.X25519PublicKey.from_public_bytes(bob_public_bytes)
            shared_secret = alice_private_key.exchange(bob_public_key)
            
            # --- PHASE 2: KEY DERIVATION ---
            # TODO: Derive the AES key by calling derive_aes_key(shared_secret)
            aes_key = derive_aes_key(shared_secret)
            
            # --- PHASE 3: SECURE PAYLOAD ---
            # TODO: Call your Week 1 encrypt_payload() using the NEW derived key.
            # TODO: Send the nonce, tag, and ciphertext to Bob.
            nonce, ciphertext, tag = encrypt_payload(message, aes_key)
            s.sendall(nonce + tag + ciphertext)
            
            print("[*] Handshake complete. Encrypted payload sent.")
            
        except ConnectionRefusedError:
            print("[-] Connection refused. Is Bob's server running?")
        except ConnectionError as e:
            print(f"[-] Handshake failed: {e}")

if __name__ == "__main__":
    start_client()