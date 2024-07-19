#include <stdio.h>
int len=0;
int main()
{
    char str[20];
    int i;
    char *p;
    printf("Enter a string: ");
    gets(str);
    p=str;
    printf("%c",*(p+1));
}
