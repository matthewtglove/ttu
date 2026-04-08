import socket
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes
from cryptography.exceptions import InvalidTag

def derive_aes_key(shared_secret: bytes) -> bytes:
    """
    TODO: Implement HKDF to derive a 32-byte AES key.
    Use SHA256 as the algorithm, length=32, salt=None, info=b'handshake data'.
    """
    pass # Students implement this

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
            
            # --- PHASE 2: KEY DERIVATION ---
            # TODO: Derive the AES key by calling derive_aes_key(shared_secret)
            
            # --- PHASE 3: RECEIVE PAYLOAD ---
            data = conn.recv(4096)
            if data:
                # TODO: Extract nonce, tag, and ciphertext. 
                # TODO: Call your Week 1 decrypt_payload() using the NEW derived key.
                print("[*] Payload decrypted successfully.")

if __name__ == "__main__":
    start_server()