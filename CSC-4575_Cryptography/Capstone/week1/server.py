import socket
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.exceptions import InvalidTag

# PRE-SHARED KEY (Week 1 Only. We will transition to ECDH in Week 2)
PSK = b'THisIsASecretKeyThatIs32Bytes!!!'

def decrypt_payload(nonce: bytes, ciphertext: bytes, tag: bytes, key: bytes) -> bytes:
    """
    TODO: Implement AES-256-GCM decryption.
    1. Construct the Cipher object using algorithms.AES(key) and modes.GCM(nonce, tag).
    2. Create a decryptor object.
    3. Decrypt the ciphertext and return the plaintext.
    """
    cipher = Cipher(algorithms.AES(key), modes.GCM(nonce, tag))
    decryptor = cipher.decryptor()
    plaintext = decryptor.update(ciphertext) + decryptor.finalize()
    return plaintext

def start_server():
    host = '0.0.0.0'
    port = 65432
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Allow immediate reuse of the port to prevent "Address already in use" errors during lab testing
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind((host, port))
        s.listen()
        print(f"[*] Bob (Server) listening on {host}:{port}...")
        
        conn, addr = s.accept()
        with conn:
            print(f"[*] Connection established from {addr}")
            
            # Receive the transmission (Nonce + Tag + Ciphertext)
            data = conn.recv(4096)
            if not data:
                print("[-] No data received.")
                return
                
            print(f"[*] Received {len(data)} bytes over the wire.")
            
            # --- Cryptographic Parsing & Decryption goes here ---
            # TODO: Extract the 12-byte nonce, 16-byte tag, and the remaining ciphertext from 'data'
            nonce = data[:12]
            tag = data[12:28]
            ciphertext = data[28:]
            
            # TODO: Call decrypt_payload()
            # TODO: Print the decoded plaintext to the console. Handle InvalidTag exceptions gracefully.
            try:
                plaintext = decrypt_payload(nonce, ciphertext, tag, PSK)
                print(f"[*] Decrypted plaintext: {plaintext.decode()}")
            except InvalidTag:
                print("[-] Decryption failed. Invalid authentication tag. Possible tampering detected.")            

if __name__ == "__main__":
    start_server()