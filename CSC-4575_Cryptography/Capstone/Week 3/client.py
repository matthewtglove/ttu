import socket
import os
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives.asymmetric import x25519
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

def load_keys():
    """Loads Alice's private identity key and Bob's public identity key."""
    with open("alice_private.pem", "rb") as f:
        alice_priv = serialization.load_pem_private_key(f.read(), password=None)
    with open("bob_public.pem", "rb") as f:
        bob_pub = serialization.load_pem_public_key(f.read())
    return alice_priv, bob_pub

def start_client():
    host, port = 'bob_node', 65432
    message = b"CLASSIFIED: The Eagle flies at midnight."
    alice_identity_priv, bob_identity_pub = load_keys()
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.connect((host, port))
            print(f"[*] Connected to Bob at {host}:{port}")
            
            # --- PHASE 1: AUTHENTICATED ECDH HANDSHAKE ---
            # TODO: 1. Generate Alice's ephemeral X25519PrivateKey
            # TODO: 2. Extract Alice's X25519 public bytes
            # TODO: 3. Use alice_identity_priv to SIGN the X25519 public bytes using padding.PSS and hashes.SHA256()
            
            # TODO: 4. Send Alice's signature (256 bytes) and Alice's X25519 public key (32 bytes) to Bob.
            
            # TODO: 5. Receive Bob's data (Format: 256-byte signature + 32-byte X25519 public key)
            # TODO: 6. Use bob_identity_pub to VERIFY Bob's signature against his X25519 public bytes.
            
            # TODO: 7. Compute the shared_secret using the verified X25519 points.
            
            # --- PHASE 2: KEY DERIVATION ---
            # TODO: Derive the AES key using HKDF (Same as Week 2)
            
            # --- PHASE 3: SECURE PAYLOAD ---
            # TODO: Encrypt and send the AES-GCM payload (Same as Week 1 & 2)
            pass
            
        except ConnectionRefusedError:
            print("[-] Connection refused. Is Bob's server running?")

if __name__ == "__main__":
    start_client()