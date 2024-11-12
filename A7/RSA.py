import math

def mod_inverse(e, phi):
    g, x, y = extended_gcd(e, phi)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % phi

def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = extended_gcd(b % a, a)
        return (g, y - (b // a) * x, x)

def main():
    p = int(input("Enter a prime number p: "))
    q = int(input("Enter a prime number q: "))
    n = p * q
    print(f"n (p * q) = {n}")

    phi = (p - 1) * (q - 1)
    print(f"Totient (phi) = {phi}")

    e = 2
    while e < phi:
        if math.gcd(e, phi) == 1:
            break
        else:
            e += 1
    print(f"Public key exponent (e) = {e}")

    d = mod_inverse(e, phi)
    print(f"Private key exponent (d) = {d}")

    message = input("Enter the message data to be encrypted: ")

    encrypted = [pow(ord(char), e, n) for char in message]
    print(f"Encrypted data asci = {encrypted}")
    
    decrypted = [(pow(char, d, n)) for char in encrypted]
    print(f"Decrypted data Ascii= {decrypted}")

    decrypted = [chr(char) for char in decrypted]
    print(f"Decrypted data = {''.join(decrypted)}")

if __name__ == "__main__":
    main()
