#include<stdio.h>
char* copy(char* str);
int main()
{
    int i, j, k;
    char str[100];
    char *cpy;
    printf("Enter the string: ");
    gets(str);
    printf("\nThe entered string is: %s\n", str);
    cpy = copy(str);
    printf("\nAfter copying it in cpy caharacter array: \n%s\n", cpy);

    return 0;
}
char* copy(char *str)
{
    static int i = 0;
    static char cpy[100];
    if(*str!='\0')
    {
        cpy[i++] = *str;
        copy(str+1);
    }
    return cpy;
}