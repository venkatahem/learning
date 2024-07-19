#include <stdio.h>

int main()
{
    char a[20],b[20];
    int i,j,len;
    printf("Enter a string:\n");
    fgets(a,20,stdin);
    len = 0;
    for(i=0;a[i]!='\0';i++)
    {
        len++;
    }
    len = len-1;
    j = 0;
    for(i=len-1;i>=0;i--)
    {
        b[j] = a[i];
        j++;
    }
    for(i=0;i<len;i++)
    {
        if(a[i] != b[i])
        {
            printf("\nNot palindrome");
            return 0;
        }
    }
    printf("\nPalindrome");
    
    return 0;
}