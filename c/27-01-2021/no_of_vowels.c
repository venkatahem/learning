#include <stdio.h>

int vowels(char *);

int main()
{
    char str[20];
    int x;
    printf("Enter a string: ");
    scanf("%s",str);
    x=vowels(str);

    printf("No.of vowels in the string = %d",x);

    return 0;
}
int vowels(char *p)
{
    static int i=0,count=0;
    if(*(p+i)!='\0')
    {   
        if( *(p+i)=='A' || *(p+i)=='E' || *(p+i)=='I' || *(p+i)=='O' || *(p+i)=='U')
        {
            count++;
        }
        else if(*(p+i)=='a' || *(p+i)=='e' || *(p+i)=='i' || *(p+i)=='o' || *(p+i)=='u')
        {
            count++;
        }
        i++;
        vowels(p);
    }
    return count;
}