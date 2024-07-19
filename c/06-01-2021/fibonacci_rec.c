#include <stdio.h>
int fib(int);
int z;
static  int a=0,b=1,c=0;
int main()
{
    int n=0;
    printf("\nEnter n: ");
    scanf("%d",&z);
    printf("\nFibonacci series\n\n");
    fib(n);

    return 0;
}
int fib(int n)
{
    if(n<z)
    {
      printf("%d ",a);
      c=a+b;
      a=b;
      b=c;
      fib(n+1);
    }
    printf("\n");
}