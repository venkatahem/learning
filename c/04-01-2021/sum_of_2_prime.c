#include <stdio.h>
int prime(int n);
int main()
{
    int n, i, x=0;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    for(i=2; i<=n/2; ++i)
    {
      if (prime(i)!=0)
        {
          if ( prime(n-i)!=0)
            {
                printf("%d = %d + %d\n", n, i, n-i);
                x=1;
            }
        }
    }
    if (x==0)
        printf("%d can't be expressed as sum of two prime numbers.",n);
    return 0;
}

int prime(int n) 
{
    int i, x=1;
    for(i=2; i<=n/2; ++i)
        if(n%i==0)
            x=0;
    return x;
}