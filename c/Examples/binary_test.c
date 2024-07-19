#include <stdio.h>
int main()
{
    long int x;
    long int a,b,res=1;
    printf("Enter a value: ");
    scanf("%ld",&x);
    a=x;
    while(a!=0)
    {
        b=a%10;
        if(b!=0&&b!=1)
        {
            res=0;
        }
        a=a/10;
    }
    res=1?printf("Entered value is binary"):printf("Entered value is not binary");

    return 0;
}