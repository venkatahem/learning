#include <stdio.h>
void reverse_string(char *);
char str1[100];
int main()
{
    int len = 0, i;
    printf("Enter a string:\n");
    gets(str1);
    for (i = 0; str1[i] != '\0'; i++)
    {
        len++;
    }
    printf("\nBefore reversing:\n");
    printf("%s\n", str1);
    printf("\nAfter reversing:\n");
    reverse_string(str1);
}
void reverse_string(char *p)
{
    if (*p != '\0')
    {
        reverse_string(p + 1);
        printf("%c", *p);
    }
}