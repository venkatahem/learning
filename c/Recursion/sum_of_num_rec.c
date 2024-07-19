#include <stdio.h>
int a=0;
int sum(int);
int main()
{
    int z,x;
    printf("Enter the number: ");
    scanf("%d",&x);
    z=sum(x);
    printf("%d is the sum",z);

    return 0;
}
int sum(int x)
{
    if(x==1)
    {
      return 1;
    }
    else
    {
        a=x+sum(x-1);
    }
    
    return a;
}