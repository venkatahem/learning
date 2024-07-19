#include <stdio.h>

int main()
{
    char str1[20];
    char str2[20];
    const char *p1;
    char *p2;
    int i;
    printf("\nEnter a string: ");
    fgets(str1,20,stdin);
    p1=str1;
    p2=str2;
    for(p1;*p1!='\0';p1++)
    {
        *(p2++)=*(p1);
    }
    printf("\n%sis the copied string",str2);

    return 0;
}