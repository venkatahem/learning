#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50],str2[20];
    char *p1,*p2;
    int res;
    p1=str1;
    p2=str2;
    printf("Enter 1st string: ");
    gets(str1);
    printf("Enter 2nd string: ");
    gets(str2);
    res=strcmp(p1,p2);

    if(res == 0)
    {
        printf("Both strings are equal.");
    }
    else if(res == -1)
    {
        printf("First string is lexicographically smaller than second.");
    }
    else
    {
        printf("First string is lexicographically greater than second.");
    }

  return 0;
}