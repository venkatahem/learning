#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    char *p;
    int len;
    p=str;
    printf("Enter a string: ");
    gets(str);
    len=strlen(p);
    printf("Length of the string:%d ",len);

    return 0;

}