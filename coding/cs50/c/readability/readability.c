#include <stdio.h>
#include <ctype.h>
#include <math.h>

int index(char text[]);

int main(void)
{
    char text[10000];
    printf("Text: ");
    scanf("%[^\n]%*c", text);
    int grade = index(text);

    // Print assigned grade
    if (grade >= 1 && grade <= 15)
        printf("Grade %i\n", grade);

    else if (grade > 15)
        printf("Grade 16+\n");

    else
        printf("Before Grade 1\n");

    return 0;
}

int index(char text[])
{
    float letters = 0, words = 1, sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        text[i] = tolower(text[i]);
        if (text[i] >= 'a' && text[i] <= 'z')
            letters++;

        if (text[i] == ' ')
            words++;

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }
    letters = (letters / words) * 100;
    sentences = (sentences / words) * 100;
    // Coleman-Liau index test formula
    int grade = round(0.0588 * letters - 0.296 * sentences - 15.8);

    return grade;
}
