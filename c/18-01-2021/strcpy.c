#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20];
    char str2[20];
    char *p1;
    char *p2;
    p1=str1;
    p2=str2;
    printf("Enter a string to copy: ");
    gets(str1);
    strcpy(p2,p1);
    printf("%s is entered string\n",str1);
    printf("\n%s is the copied string",str2);

    return 0;
}