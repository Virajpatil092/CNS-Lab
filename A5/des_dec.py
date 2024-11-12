from Crypto.Cipher import DES
from Crypto.Util.Padding import unpad


def des_decrypt(cipher_text, key):
    cipher = DES.new(key, DES.MODE_ECB)
    decrypted_text = unpad(cipher.decrypt(cipher_text), DES.block_size)
    return decrypted_text.decode()


def main():
    print("\nDES Decryption in ECB Mode")

    encrypted_hex = input("Enter the encrypted text (in hexadecimal): ")
    cipher_text = bytes.fromhex(encrypted_hex)

    key_hex = input("Enter the encryption key (in hexadecimal): ")
    key = bytes.fromhex(key_hex)

    decrypted_text = des_decrypt(cipher_text, key)
    print(f"\nDecrypted Text: {decrypted_text}\n")


if __name__ == "__main__":
    main()
