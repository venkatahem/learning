#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50],str2[20];
    char *p1,*p2;
    p1=str1;
    p2=str2;
    printf("Enter 1st string: ");
    gets(str1);
    printf("Enter 2nd string: ");
    gets(str2);
    strcat(p1,p2);
    printf("After concatenation %s",str1);

    return 0;

}