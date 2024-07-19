#include <stdio.h>

long long int dtob(long long int x)
{
    long long int sum=0,y;
    while(x != 0)
    {
        y = x%2;
        sum = (sum*10)+y;
        x = x/2;
    }
    return sum;
}
void main()
{
    long long int a;
    long long int z,b,sum = 0;
    printf("\nEnter a number: ");
    scanf("%ld",&a);
    z = dtob(a);
    while(z != 0)
    {
        b = z%2;
        sum = sum*10 + b;
        z = z/2;
    }
    z = sum;
    printf("\n%ld\n",z);
}