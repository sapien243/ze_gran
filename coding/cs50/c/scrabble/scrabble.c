#include <ctype.h>
#include <stdio.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// ------------ a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,, r, s, t, u, v, w, x, y, z,

int compute_score(char word[]);

int main(void)
{
    char word1[100] = {'\0'}, word2[100] = {'\0'};

    // Get input from player 1
    printf("Player 1: ");
    scanf("%[^\n]%*c", word1);
    // Get input from player 2
    printf("Player 2: ");
    scanf("%[^\n]%*c", word2);

    // Score both words
    int score1 = compute_score(word1), score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
        printf("Player 1 wins!\n");

    else if (score1 < score2)
        printf("Player 2 wins!\n");

    else
        printf("Tie!\n");

    return 0;
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int total = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);

        if (word[i] >= 'a' && word[i] <= 'z')
            total += POINTS[word[i] - 'a'];
    }
    return total;
}
