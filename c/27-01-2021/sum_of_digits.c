#include <stdio.h>

int main()
{
    int n,x,y,sum=0;
    printf("\nEnter a number to sum it's digits: ");
    scanf("%d",&n);
    x=n;
    while(x)
    {
        y=x%10;
        if(y==4 || y==7)
        {
            x=x/10;
            continue;
        }
        sum=sum+y;
        x=x/10;
    }
    printf("Sum of the digits on a condition (i.e digit not equal to 4 or 7) = %d",sum);
    return 0;
}