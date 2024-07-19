#include <stdio.h>
 
int fact(int);
 
void main()
{
 int n,factorial;
 
  	printf("Enter a number: ");
  	scanf("%d",&n);
    while (n>0)
    {
     factorial=fact(n);
     printf("Factorial of the num(%d) = %d\n",n,factorial);
     --n;
    }
}
int fact(int n)
{
    int f=1;
    while(n>0)
    {
        f=f*n;
        --n;
    }
    return f;
}