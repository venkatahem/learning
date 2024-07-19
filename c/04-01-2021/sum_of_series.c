#include <stdio.h>
int sum(int);
int main()
{
    int x=5;
    int s;
    s=sum(x);
    printf("Sum of the series 1!/1 + 2!/2 + 3!/3 + 4!/4 + 5!/5 is\n%d",s);

    return 0;
}
int sum(int x)
{
    int fact=1;
    int i=1,a=1;
    int sum=0;
    for(i=1;i<=x;i++)
    {
        for(a=1;a<=i;a++)
        {
            fact=fact*a;
        }
        fact=fact/i;
        sum=sum+fact;
        fact=1;
    }
    return sum;
}