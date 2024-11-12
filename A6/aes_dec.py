from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad


def aes_decrypt_cbc(iv, cipher_text, key):
    """
    Decrypt the cipher text using AES algorithm in CBC mode.

    Parameters:
    iv (bytes): The initialization vector used during encryption.
    cipher_text (bytes): The encrypted text to be decrypted.
    key (bytes): The decryption key (must be 16, 24, or 32 bytes long).

    Returns:
    str: The decrypted plain text.
    """
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_text = unpad(cipher.decrypt(cipher_text), AES.block_size)
    return decrypted_text.decode()


if __name__ == "__main__":
    # Input key (in hexadecimal) and convert it back to bytes
    key_hex = input("\nEnter the key (in hexadecimal): ")
    key = bytes.fromhex(key_hex)

    # Input initialization vector (IV)
    iv_hex = input("\nEnter the initialization vector (IV) (in hexadecimal): ")
    iv = bytes.fromhex(iv_hex)

    # Input encrypted text
    encrypted_text_hex = input("\nEnter the encrypted text (in hexadecimal): ")
    encrypted_text = bytes.fromhex(encrypted_text_hex)

    # Decrypt the ciphertext
    decrypted_text = aes_decrypt_cbc(iv, encrypted_text, key)
    print(f"\nDecrypted Text: {decrypted_text}\n")
