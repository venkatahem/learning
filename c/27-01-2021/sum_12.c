#include <stdio.h>

int main()
{
    int n=100,x,y,sum=0;
    int z=1;
    printf("\nFirst 20 numbers with sum of its digits=12 starting from 100\n\n");
    while(z<21)
    {
        x=n;
        while(x>0)
            {
                y=x%10;
                sum=sum+y;
                x=x/10;
            }
        if(sum==12)
        {
            printf("%d  ",n);
            z++;
        }
        n++;
        sum=0;
    }

    return 0;
}