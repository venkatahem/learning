#include <stdio.h>

int main()
{
    char str[100];
    int i,j;
    gets(str);
    str[0]='A';
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            str[i+1]='A';
        }
    }
    printf("%s",str);

    return 0;
}