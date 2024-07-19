#include <stdio.h>
#include <stdlib.h>

void main()
{
    char ch[2];
    int a;
    printf("Give the input: ");
    scanf("%c", &ch[0]);
    a = atoi(ch);
    if (ch[0] >= 'A' && ch[0] <= 'Z')
    {
        printf("Entered character is a Upper Case alphabet");
    }
    else if (ch[0] >= 'a' && ch[0] <= 'z')
    {
        printf("Entered character is a Lower Case alphabet");
    }
    else if (a >= 1 && a <= 9)
    {
        printf("Entered character is a numerical digit");
    }
    else
    {
        printf("Entered character is a special symbol");
    }
}