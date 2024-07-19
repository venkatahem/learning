#include <stdio.h>
int primecheck(int);
int main()
{
    int n,count=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    count=primecheck(n);
    if(count==2)
    {
        printf("%d is a prime number",n);
    }
    else
    {
        printf("%d is not a prime number",n);
    }
    
}
int primecheck(int n)
{
    int a=0,i;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            a++;
        }
    }
    return a;
}