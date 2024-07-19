#include <stdio.h>
int main()
{
    float n,i,fact=1;
    printf("Enter a number: ");
    scanf("%f",&n);
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("%f",fact);
}