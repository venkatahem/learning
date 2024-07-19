#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char *strarr[20];
void copys(FILE *fs,FILE *fd)
{
    char line[60],temp[60];
    int n,i=0;
    fseek(fs,0,0);
    while(!feof(fs))
    {
        fgets(line,60,fs);
        printf("Enter the number of this line: %s :",line);
        scanf("%d",&n);
        strarr[n-1] = (char*)malloc(60);
        strcpy(strarr[n-1],line);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        fputs(strarr[j],fd);
    }
}
int main()
{
    FILE *fs,*fd;
    fs=fopen("file1.txt","a+");
    fd=fopen("file2.txt","r+");
    copys(fs,fd);
}