#include <stdio.h>

void main()
{
    FILE *f1;
    char a[50],ch;
    int i,j;

    f1 = fopen("org.txt","r+");
    for(i=0;!feof(f1);i++)
    {
        ch = getc(f1);
        a[i] = ch;
    }
    printf("\nReverse of file1:\n");
    for(j=i-1;j>=0;j--)
    {
        printf("%c",a[j]);
    }
}