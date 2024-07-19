#include <stdio.h>
#include <string.h>
void print(char *, int);
int main()
{
    char str1[20];
    char str2[10];
    char *p1;
    const char const *p2;
    int len=0,len1=0;
    int i,j;
    printf("Enter the first string: ");
    scanf("%s",str1);
    printf("Enter the second string: ");
    scanf("%s",str2);
    p1=str1;
    p2=str2;
    printf("\nFirst string\n");
    len=strlen(str1);
    print(p1,len);
    printf("\nSecond string\n");
    len1=strlen(str2);
    print(str2,len1);
    for(i=len,j=0;i<len+len1,j<len1;i++,j++)
    {
       *(p1+i)=*(p2+j); 
    }
    printf("\nAfter concatenation\n");
    len1=strlen(str1);
    print(str1,len1);

    return 0;
}
void print(char *p,int l)
{
    int i;
    for(i=0;i<l;i++)
    {
        printf("%c",*(p+i));
    }
    printf("\n");
}