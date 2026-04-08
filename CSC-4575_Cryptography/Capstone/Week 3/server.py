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
            # --- PHASE 1: AUTHENTICATED ECDH HANDSHAKE ---
            # TODO: 1. Generate Bob's ephemeral X25519PrivateKey
            # TODO: 2. Extract Bob's X25519 public bytes
            # TODO: 3. Use bob_identity_priv to SIGN the X25519 public bytes using padding.PSS and hashes.SHA256()
            
            # TODO: 4. Receive Alice's data (Format: 256-byte signature + 32-byte X25519 public key)
            # TODO: 5. Use alice_identity_pub to VERIFY Alice's signature against her X25519 public bytes.
            #          (If verification fails, cryptography will raise an InvalidSignature exception. Let it crash the connection.)
            
            # TODO: 6. Send Bob's signature and Bob's X25519 public bytes to Alice.
            # TODO: 7. Compute the shared_secret using the verified X25519 points.
            
            # --- PHASE 2: KEY DERIVATION ---
            # TODO: Derive the AES key using HKDF (Same as Week 2)
            
            # --- PHASE 3: RECEIVE PAYLOAD ---
            # TODO: Receive and decrypt the AES-GCM payload (Same as Week 1 & 2)
            pass

if __name__ == "__main__":
    start_server()