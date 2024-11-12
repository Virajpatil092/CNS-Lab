#include <iostream>
#include <string>
#include <vector>
using namespace std;
string railFenceEncrypt(string text, int key)
{
    if (key <= 1)
        return text;
    vector<string> rail(key);
    int row = 0;
    int dir = 1;
    for (int i = 0; i < text.length(); i++)
    {
        rail[row] += text[i];
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;
        row += dir;
    }
    string result = "";
    for (int i = 0; i < key; i++)
        result += rail[i];
    return result;
}
string railFenceDecrypt(string cipher, int key)
{
    if (key <= 1)
        return cipher;
    vector<int> pos(key, 0);
    int row = 0, dir = 1;
    for (int i = 0; i < cipher.length(); i++)
    {
        pos[row]++;
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;
        row += dir;
    }
    vector<string> rail(key);
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < pos[i]; j++)
            rail[i] += cipher[index++];
    string result = "";
    row = 0, dir = 1;
    for (int i = 0; i < cipher.length(); i++)
    {
        result += rail[row][0];
        rail[row].erase(rail[row].begin());
        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;
        row += dir;
    }
    return result;
}
int main()
{
    string text;
    int key;
    cout << "Enter text for Rail Fence Cipher: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;
    string encryptedText = railFenceEncrypt(text, key);
    string decryptedText = railFenceDecrypt(encryptedText, key);
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;
    return 0;
}
