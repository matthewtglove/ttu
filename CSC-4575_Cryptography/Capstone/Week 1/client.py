import socket
import os
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

# PRE-SHARED KEY (Week 1 Only. We will transition to ECDH in Week 2)
PSK = b'THisIsASecretKeyThatIs32Bytes!!!'

def encrypt_payload(plaintext: bytes, key: bytes) -> tuple[bytes, bytes, bytes]:
    """
    TODO: Implement AES-256-GCM encryption.
    1. Generate a secure 12-byte nonce using os.urandom().
    2. Construct the Cipher object using algorithms.AES(key) and modes.GCM(nonce).
    3. Create an encryptor object and encrypt the plaintext.
    4. Return the (nonce, ciphertext, tag).
    """
    pass # Students implement this

def start_client():
    # Docker automatically resolves container names to internal IPs
    host = 'bob_node' 
    port = 65432
    
    # The payload we want to protect from Wireshark
    message = b"CLASSIFIED: The Eagle flies at midnight."
    
    # --- Cryptographic Implementation goes here ---
    # TODO: Call encrypt_payload() with the message and PSK.
    
    # Network Transmission
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.connect((host, port))
            print(f"[*] Connected to Bob at {host}:{port}")
            
            # TODO: Transmit the data. 
            # Format requirement: nonce (12 bytes) + tag (16 bytes) + ciphertext
            # Example: s.sendall(nonce + tag + ciphertext)
            
            print("[*] Encrypted payload sent over the wire.")
        except ConnectionRefusedError:
            print("[-] Connection refused. Is Bob's node running the server script?")

if __name__ == "__main__":
    start_client()