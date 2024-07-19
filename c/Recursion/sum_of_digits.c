#include <stdio.h>
int sum(int);
int main()
{
    int n,y;
    printf("Enter a number: ");
    scanf("%d",&n);
    y=sum(n);
    printf("Sum of the digits in the number = %d",y);

    return 0;
}
int sum(int n)
{
    static int x=0;
    int y;
    if(n!=0)
    {
      y=n%10;
      x=x+y;
      sum(n/10);
    }
    return x;
}