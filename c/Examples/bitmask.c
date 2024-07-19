#include <stdio.h>

long long int dtob(int x)
{
    int sum=0,y,z=1;
    while(x != 0)
    {
        y = x%2;
        sum = (sum+y)*z;
        z = z*10;
        x = x/2;
    }
    return sum;
}
void main()
{
    int a;
    long long int z,b,sum = 0;
    printf("\nEnter a number: ");
    scanf("%d",&a);
    z = dtob(a);
    printf("\n%ld\n",z);
}