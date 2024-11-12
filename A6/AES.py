from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes


def aes_encrypt(plain_text, key):
    cipher = AES.new(key, AES.MODE_CBC)
    iv = cipher.iv
    padded_text = pad(plain_text.encode(), AES.block_size)
    encrypted_text = cipher.encrypt(padded_text)
    return iv, encrypted_text


def aes_decrypt(iv, cipher_text, key):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_text = unpad(cipher.decrypt(cipher_text), AES.block_size)
    return decrypted_text.decode()


def main():
    print("\nAES Encryption and Decryption")

    # Generate a random 32-byte key for AES (256-bit)
    key = get_random_bytes(32)
    print(f"\nGenerated Key (in hexadecimal): {key.hex()}")

    # Input plaintext
    plain_text = input("\nEnter the plain text to encrypt: ")

    # Encrypt the plaintext
    iv, encrypted_text = aes_encrypt(plain_text, key)
    print(f"\nInitialization Vector (IV) (in hexadecimal): {iv.hex()}")
    print(f"\nEncrypted Text (in hexadecimal): {encrypted_text.hex()}")

    # Decrypt the ciphertext
    decrypted_text = aes_decrypt(iv, encrypted_text, key)
    print(f"\nDecrypted Text: {decrypted_text}")


if __name__ == "__main__":
    main()
