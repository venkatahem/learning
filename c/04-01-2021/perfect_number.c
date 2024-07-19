#include <stdio.h>
int perfect(int);
int main()
{
    int i;
    int f=0;
    for (i=2;i<500;i++)
    {
        f=perfect(i);
        if(f==1)
        {
            printf("\n%d is a perfect number\n",i);
        }
    }

    return 0;
}
int perfect(int i)
{
    int sum=0;
    int a;
    int b;
    for(a=1;a<i;a++)
    {
        if(i%a==0)
        {
            sum=sum+a;
        }
    }
    if(sum==i)
    {
        b=1;
    }
    else
    {
        b=0;
    }
    return b;
    
}