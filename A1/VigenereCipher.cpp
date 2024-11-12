#include <iostream>
using namespace std;

string generateKey(string text, string key)
{
    int x = text.size();
    for (int i = 0; i < x; i++)
    {
        if (key.size() == text.size())
            break;
        key.push_back(key[i % key.size()]);
    }
    return key;
}

string vigenereEncrypt(string text, string key)
{
    string cipher_text;
    for (int i = 0; i < text.size(); i++)
    {
        char x = (text[i] + key[i]) % 26;
        x += 'A';
        cipher_text.push_back(x);
    }
    return cipher_text;
}

string vigenereDecrypt(string cipher_text, string key)
{
    string orig_text;
    for (int i = 0; i < cipher_text.size(); i++)
    {
        char x = (cipher_text[i] - key[i] + 26) % 26;
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

int main()
{
    string text, key;

    cout << "Enter text to encrypt (Vigenere Cipher): ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, key);

    string generatedKey = generateKey(text, key);
    string encrypted = vigenereEncrypt(text, generatedKey);
    string decrypted = vigenereDecrypt(encrypted, generatedKey);

    cout << "Encrypted: " << encrypted << "\n";
    cout << "Decrypted: " << decrypted << "\n";

    return 0;
}
