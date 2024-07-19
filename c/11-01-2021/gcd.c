#include<stdio.h>

int GCD(int a,int b);
int main()
{
  int a,b,gcd;
  printf("Enter first number: ");
  scanf("%d",&a);
  printf("Enter second number: ");
  scanf("%d",&b);
  gcd = GCD(a,b);
  printf("\nThe GCD of %d and %d is: %d\n\n",a,b,gcd);
  return 0;
}
int GCD(int a,int b)
{
     while(a!=b)
     {
          if(a>b)
              return GCD(a-b,b);
          else
             return GCD(a,b-a);
     }
     return a;
}