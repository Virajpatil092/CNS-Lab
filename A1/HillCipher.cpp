#include <iostream>
#include <vector>
using namespace std;

vector<int> multiplyMatrix(vector<vector<int>> keyMatrix, vector<int> messageVector)
{
    vector<int> result(3);
    for (int i = 0; i < 3; i++)
    {
        result[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            result[i] += keyMatrix[i][j] * messageVector[j];
        }
        result[i] %= 26;
    }
    return result;
}

string hillEncrypt(string message, vector<vector<int>> keyMatrix)
{
    vector<int> messageVector(3);
    string encrypted = "";

    for (int i = 0; i < message.length(); i += 3)
    {
        for (int j = 0; j < 3; j++)
        {
            messageVector[j] = message[i + j] - 'A';
        }

        vector<int> encryptedVector = multiplyMatrix(keyMatrix, messageVector);

        for (int j = 0; j < 3; j++)
        {
            encrypted += (encryptedVector[j] + 'A');
        }
    }
    return encrypted;
}

int main()
{
    string message;
    vector<vector<int>> keyMatrix(3, vector<int>(3));

    cout << "Enter text to encrypt (Hill Cipher): ";
    getline(cin, message);

    cout << "Enter 3x3 key matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> keyMatrix[i][j];
        }
    }

    string encrypted = hillEncrypt(message, keyMatrix);
    cout << "Encrypted: " << encrypted << "\n";

    return 0;
}
