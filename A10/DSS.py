from cryptography.hazmat.primitives.asymmetric import dsa
from cryptography.hazmat.primitives import hashes

private_key = dsa.generate_private_key(key_size=2048)


message = b"This is a message for digital signature."

signature = private_key.sign(
    message,
    hashes.SHA256()
)


print(f"Signature: {signature.hex()}")

public_key = private_key.public_key()

try:
    public_key.verify(
        signature,
        message,
        hashes.SHA256()
    )
    print("Signature verified successfully!")
except Exception as e:
    print("Signature verification failed:", str(e))
