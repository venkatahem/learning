#include<stdio.h>
#include<stdlib.h>
void createfile(FILE *fp)
{
    char str[90];
    do
    {
        fgets(str,90,stdin);
        fputs(str,fp);
    }while(str[0]!='\n');
}
void copyf(FILE *fs,FILE *fd)
{
    char str[90];
    do
    {
        fgets(str,90,fs);
        if (str[0]!='/'&&str[1]!='/')
        {
            fputs(str,fd);
        }
    } while (str[0]!='\n');
}
int main()
{
    FILE *fs,*fd;
    fs=fopen("org.txt","w+");
    fd=fopen("cpy.txt","w+");
    printf("Enter the text for the org file\n");
    createfile(fs);
    fseek(fs,0,0);
    copyf(fs,fd);
}