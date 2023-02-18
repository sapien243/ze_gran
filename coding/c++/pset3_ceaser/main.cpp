#include <iostream>

using namespace std;

bool isNum(char num[]);
string caesar(int k, string plaintext);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "One argument expected!" << endl;
        return 1;
    }
    if (isNum(argv[1]) == false)
    {
        cout << "Argument should be a positive integer!" << endl;
        return 1;
    }
    int k = stoi(argv[1]);
    string input = "\0";

    cout << "Enter your text:" << endl;
    getline(cin, input);

    string ciphertext = caesar(k, input);
    cout << ciphertext << endl;

    return 0;
}

bool isNum(char num[])
{
    for (int i = 0; num[i] != '\0'; i++)
        if (num[i] < '0' || num[i] > '9')
            return false;
    return true;
}

string caesar(int k, string plaintext)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            plaintext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
    }
    return plaintext;
}