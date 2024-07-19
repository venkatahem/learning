#include <stdio.h>

int main()
{
    char str[20];
    const char* p;
    int len=0;
    const int* l;
    p=str;
    l=&len;
    printf("\nEnter a string to find length: ");
    scanf("%s",str);
    for(p;*p!='\0';p++)
    {
        len++;
    }
    printf("\n%d is the length of the entered string",*l);

    return 0;
}