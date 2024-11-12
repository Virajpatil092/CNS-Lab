#include <iostream>
#include <vector>
using namespace std;

void generateKeyMatrix(string key, char keyMatrix[5][5])
{
    vector<int> mark(26, 0);
    int i = 0, j = 0;

    for (char c : key)
    {
        if (c == 'J')
            c = 'I';
        if (mark[c - 'A'] == 0)
        {
            keyMatrix[i][j] = c;
            mark[c - 'A'] = 1;
            j++;
            if (j == 5)
            {
                j = 0;
                i++;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (c == 'J')
            continue;
        if (mark[c - 'A'] == 0)
        {
            keyMatrix[i][j] = c;
            mark[c - 'A'] = 1;
            j++;
            if (j == 5)
            {
                j = 0;
                i++;
            }
        }
    }
}

void search(char keyMatrix[5][5], char a, char b, int pos[])
{
    if (a == 'J')
        a = 'I';
    if (b == 'J')
        b = 'I';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyMatrix[i][j] == a)
            {
                pos[0] = i;
                pos[1] = j;
            }
            if (keyMatrix[i][j] == b)
            {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}

string playfairEncrypt(string text, string key)
{
    char keyMatrix[5][5];
    generateKeyMatrix(key, keyMatrix);

    string result = "";
    for (int i = 0; i < text.length(); i += 2)
    {
        if (i + 1 == text.length() || text[i] == text[i + 1])
        {
            text.insert(i + 1, "X");
        }

        int pos[4];
        search(keyMatrix, text[i], text[i + 1], pos);

        if (pos[0] == pos[2])
        {
            result += keyMatrix[pos[0]][(pos[1] + 1) % 5];
            result += keyMatrix[pos[2]][(pos[3] + 1) % 5];
        }
        else if (pos[1] == pos[3])
        {
            result += keyMatrix[(pos[0] + 1) % 5][pos[1]];
            result += keyMatrix[(pos[2] + 1) % 5][pos[3]];
        }
        else
        {
            result += keyMatrix[pos[0]][pos[3]];
            result += keyMatrix[pos[2]][pos[1]];
        }
    }
    return result;
}

string playfairDecrypt(string text, string key)
{
    char keyMatrix[5][5];
    generateKeyMatrix(key, keyMatrix);

    string result = "";
    for (int i = 0; i < text.length(); i += 2)
    {
        int pos[4];
        search(keyMatrix, text[i], text[i + 1], pos);

        if (pos[0] == pos[2])
        {
            result += keyMatrix[pos[0]][(pos[1] - 1 + 5) % 5];
            result += keyMatrix[pos[2]][(pos[3] - 1 + 5) % 5];
        }
        else if (pos[1] == pos[3])
        {
            result += keyMatrix[(pos[0] - 1 + 5) % 5][pos[1]];
            result += keyMatrix[(pos[2] - 1 + 5) % 5][pos[3]];
        }
        else
        {
            result += keyMatrix[pos[0]][pos[3]];
            result += keyMatrix[pos[2]][pos[1]];
        }
    }
    return result;
}

int main()
{
    string text, key;

    cout << "Enter text to encrypt (Playfair Cipher): ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, key);

    string encrypted = playfairEncrypt(text, key);
    string decrypted = playfairDecrypt(encrypted, key);

    cout << "Encrypted: " << encrypted << "\n";
    cout << "Decrypted: " << decrypted << "\n";

    return 0;
}
