#include <iostream>
using namespace std;

string caesarEncrypt(string text, int shift)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
        if (isalpha(ch))
        {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + shift) % 26 + offset;
        }
        result += ch;
    }
    return result;
}

string caesarDecrypt(string text, int shift)
{
    return caesarEncrypt(text, 26 - shift);
}

int main()
{
    string text;
    int shift;

    cout << "Enter text to encrypt (Caesar Cipher): ";
    getline(cin, text);
    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = caesarEncrypt(text, shift);
    string decrypted = caesarDecrypt(encrypted, shift);

    cout << "Encrypted: " << encrypted << "\n";
    cout << "Decrypted: " << decrypted << "\n";

    return 0;
}
