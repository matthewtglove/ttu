import socket
import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes

def derive_aes_key(shared_secret: bytes) -> bytes:
    """
    TODO: Implement HKDF to derive a 32-byte AES key.
    Must match the Server's HKDF parameters exactly.
    """
    pass # Students implement this

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
            
            # --- PHASE 2: KEY DERIVATION ---
            # TODO: Derive the AES key by calling derive_aes_key(shared_secret)
            
            # --- PHASE 3: SECURE PAYLOAD ---
            # TODO: Call your Week 1 encrypt_payload() using the NEW derived key.
            # TODO: Send the nonce, tag, and ciphertext to Bob.
            
            print("[*] Handshake complete. Encrypted payload sent.")
            
        except ConnectionRefusedError:
            print("[-] Connection refused. Is Bob's server running?")

if __name__ == "__main__":
    start_client()