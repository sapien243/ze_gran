#include <stdio.h>

int main(void)
{
    char name[100] = {'\0'};
    //get name and store it in a variable
    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);
    fflush(stdin);

    // print hello, name
    printf("Hello, %s\n", name);
}