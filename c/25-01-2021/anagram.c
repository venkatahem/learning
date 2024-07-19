#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void anagram(char *, char *,int );

int main()
{
    char str1[20], str2[20];
    int a,b;
    printf("\nEnter string 1: ");
    scanf("%s",str1);
    a=strlen(str1);
    printf("\nEnter string 2: ");
    scanf("%s",str2);
    b=strlen(str2);
    if(a!=b)
    {
        printf("\n%s and %s are not anagrams\n",str1,str2);
    }
    else
    {
        anagram(str1,str2,a);
    }

    return 0;
}
void anagram(char *p,char *q,int n)
{
    char x,y;
    int i=0,j=0;
    for(i;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(*(p+i) > *(p+j))
           {
               x = *(p+i);
               *(p+i) = *(p+j);
               *(p+j) = x;
           }
           if(*(q+i) > *(q+j))
           {
               y = *(q+i);
               *(q+i) = *(q+j);
               *(q+j) = y;
           }
        }
    }
    for(i=0;i<n;i++)
    {
        if(*(p+i) != *(q+i))
        {
            printf("Both strings are not anagrams");
            exit(0);
        }
    }
    printf("\nBoth strings are anagrams\n");
}