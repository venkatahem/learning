#include <stdio.h>

void main()
{
    char ch;
    printf("Enter a alphabet: ");
    scanf("%c", &ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        printf("\nEntered alphabet is a VOWEL\n");
    }
    else
    {
        printf("\nEntered alphabet is NOT a VOWEL");
    }
}