#include <iostream>
#include <string>
#include <vector>
using namespace std;
string rowColumnEncrypt(string text, int rows, int cols)
{
    vector<vector<char>> grid(rows, vector<char>(cols, ' '));
    int index = 0;
    for (int i = 0; i < rows && index < text.length(); i++)
        for (int j = 0; j < cols && index < text.length(); j++)
            grid[i][j] = text[index++];

    string encryptedText = "";
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            encryptedText += grid[i][j];

    return encryptedText;
}
string rowColumnDecrypt(string cipher, int rows, int cols)
{
    vector<vector<char>> grid(rows, vector<char>(cols, ' '));
    int index = 0;
    for (int j = 0; j < cols && index < cipher.length(); j++)
        for (int i = 0; i < rows && index < cipher.length(); i++)
            grid[i][j] = cipher[index++];
    string decryptedText = "";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            decryptedText += grid[i][j];
    return decryptedText;
}
int main()
{
    string text;
    int rows, cols;
    cout << "Enter text for Row-Column Cipher: ";
    getline(cin, text);
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    string encryptedText = rowColumnEncrypt(text, rows, cols);
    string decryptedText = rowColumnDecrypt(encryptedText, rows, cols);
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;
    return 0;
}
