#include <stdio.h>
#include <ctype.h>

char *cipher(char *key, char text[]);

int main(int argc, char *argv[])
{
    // check if 2 arguments are entered
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // check if the characters are alphabetical
    int len = 0;
    for (; argv[1][len]; len++)
    {
        argv[1][len] = tolower(argv[1][len]);

        if (argv[1][len] < 'a' || argv[1][len] > 'z')
        {
            printf("The characters should be alphabetical.\n");
            return 1;
        }
    }
    // check if 26 characters are entered
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check if the characters are unique
    for (int i = 0; argv[1][i]; i++)
    {
        for (int j = (i + 1); j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("The characters should not repeat.\n");
                return 1;
            }
        }
    }
    char text[10000] = {'\0'};
    // Take input from user
    printf("plaintext: ");
    scanf("%[^\n]%*c", text);
    // Print cipher
    printf("ciphertext: %s\n", cipher(argv[1], text));

    return 0;
}

char *cipher(char *key, char text[])
{
    for (int i = 0; text[i]; i++)
    {
        // encrypt lowercase alphabets
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = key[text[i] - 'a'];

        // encrypt uppercase alphabets
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'] - 32;

    }
    return text;
}
