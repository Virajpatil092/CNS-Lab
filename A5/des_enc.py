from Crypto.Cipher import DES
from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes


def des_encrypt(plain_text, key):
    cipher = DES.new(key, DES.MODE_ECB)
    padded_text = pad(plain_text.encode(), DES.block_size)
    encrypted_text = cipher.encrypt(padded_text)
    return encrypted_text


def main():
    print("\nDES Encryption in ECB Mode")

    key = get_random_bytes(8)
    print(f"\nGenerated Key (in hexadecimal): {key.hex()}\n")

    plain_text = input("Enter the plain text to encrypt: ")

    encrypted_text = des_encrypt(plain_text, key)
    print(f"\nEncrypted Text (in hexadecimal): {encrypted_text.hex()}")
    print(f"\nEncryption Key (in hexadecimal): {key.hex()}\n")


if __name__ == "__main__":
    main()
