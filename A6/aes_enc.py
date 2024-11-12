from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes


def aes_encrypt_cbc(plain_text, key):
    """
    Encrypt the plain text using AES algorithm in CBC mode.

    Parameters:
    plain_text (str): The text to be encrypted.
    key (bytes): The encryption key (must be 16, 24, or 32 bytes long).

    Returns:
    tuple: The initialization vector (IV) and the encrypted cipher text.
    """
    cipher = AES.new(key, AES.MODE_CBC)
    iv = cipher.iv
    padded_text = pad(plain_text.encode(), AES.block_size)
    encrypted_text = cipher.encrypt(padded_text)
    return iv, encrypted_text


# Example usage for encryption
if __name__ == "__main__":
    # Generate a random 32-byte key for AES (256-bit)
    key = get_random_bytes(32)
    print(f"\nGenerated Key (in hexadecimal): {key.hex()}")

    # Input plaintext
    plain_text = input("\nEnter the plain text to encrypt: ")

    # Encrypt the plaintext
    iv, encrypted_text = aes_encrypt_cbc(plain_text, key)
    print(f"\nInitialization Vector (IV) (in hexadecimal): {iv.hex()}")
    print(f"\nEncrypted Text (in hexadecimal): {encrypted_text.hex()}\n")
