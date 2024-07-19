#include<stdio.h>
char* rev(char* str);
int main()
{
    int i, j, k;
    char str[100];
    char *reve;
    printf("\nEnter the string: ");
    gets(str);
    printf("\nThe original string is: %s\n", str);
    reve = rev(str);
    printf("\nThe reversed string is: %s\n", reve);

    return 0;
}
char* rev(char *str)
{
    static int i = 0;
    static char reve[100];
    if(*str!='\0')
    {
        rev(str+1);
        reve[i++] = *str;
    }
    return reve;
}