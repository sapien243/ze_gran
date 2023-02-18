#include <stdio.h>
#include <string.h>

int inputCheck(char card[]);
int luhnCheck(char card[], int len);

int main(void)
{
    char card[64] = {'\0'};
    printf("This program validates some credit card numbers\n");
    do
    {
        printf("Enter credit card number:\n-> ");
        scanf_s("%[^\n]%*c", card);
        fflush(stdin);
    } while (inputCheck(card) == 1);

    int len = strlen(card);
    int check = luhnCheck(card, len);

	if (check == 0 && len == 15 && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
	{
		printf("AMEX\n");
	}
    else if (check == 0 && len == 16 && card[0] == '5' && (card[1] > '0' && card[1] < '6'))
    {
        printf("MASTERCARD\n");
    }
    else if (check == 0 && (len == 13 || len == 16) && card[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int inputCheck(char card[])
{
    for (int i = 0; card[i] != '\0'; i++)
    {
        if (card[i] < '0' || card[i] > '9')
        {
            printf("Input is not a number\n");
            return 1;
        }
        if (i == 16)
        {
            printf("Number is too long\n");
            return 1;
        }
    }
    return 0;
}

int luhnCheck(char card[], int len)
{
    int a = len - 1, sum = 0;
    for (; a >= 0; a -= 2)
    {
        int x = card[a] - '0';
        int y = (a == 0) ? 0 : (card[a - 1] - '0') * 2;
        y = (y / 10) + (y % 10);
        sum = sum + x + y;
    }
    if (sum % 10 == 0)
    {
        return 0;
    }
    return 1;
}
