#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f1,*f2;
    int i,j,k;
    char str[30],ch;

    f1=fopen("file1.txt","r+");
    f2=fopen("file2.txt","r+");
    printf("\n\nContents of file1:\n");
    while(!feof(f1))
    {
        ch = fgetc(f1);
        putchar(ch);
    }
    printf("\n\nContents of file2:\n");
    while(!feof(f2))
    {
        ch = fgetc(f2);
        putchar(ch);
    }
    printf("\n\nEnter the position to insert the contents of file 2: ");
    scanf("%d",&i);
    fseek(f1,i,0);
    ch=getc(f1);
    for(j=0;!feof(f1);j++)
    {
      str[j]=ch;
      ch=getc(f1);
    }
    fseek(f1,i,0);
    ch = getc(f2);
    while (!feof(f2))
    {
        putc(ch,f1);
        ch = getc(f2);
    } 
    for(k=0;str[k]!='\0';k++)
    {
        putc(str[k],f1);
    }
    
    
    return 0;
}