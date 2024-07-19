#include <stdio.h>
void reverse_string(int);
char str1[100];
int main()
{
    int len=0,i;
    printf("Enter a string:\n");
    gets(str1);
    for(i=0;str1[i]!='\0';i++)
    {
        len++;
    }
    printf("\nBefore reversing:\n");
    printf("%s\n",str1);
    printf("\nAfter reversing:\n");
    reverse_string(len);
}
void reverse_string(int len)
{
    if(len>=0)
    {
        printf("%c",str1[len]);
        reverse_string(len-1);
    }
}