#include <stdio.h>

int main(void)
{
    char input = 'o';
    do
    {
        printf("Height: ");
        scanf("%[^\n]%*c", &input);
        fflush(stdin);
    } while (input < '1' || input > '8');
    int height = input - '0';

    //shift row
    for (int i = 1; i <= height; i++)
    {
        //spaces
        for (int space = height - i; space > 0; space--)
            printf(" ");
        //first half
        for (int half1 = 0; half1 < i; half1++)
            printf("#");
        //middle gap
        printf("  ");
        //second half
        for (int half2 = 0; half2 < i; half2++)
            printf("#");
        //next line
        printf("\n");
    }
}
