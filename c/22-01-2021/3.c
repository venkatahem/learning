#include <stdio.h>
int reverse(int );

int main()
{
    int x,flag=1,i;
    printf("Enter a number: ");
    scanf("%d",&x);
    for(i=2;i< x/2;i++)
    {
        if(x%i==0)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        i=reverse(x);
         printf("%d",i);
    }
    else
    {
        printf("Not a prime number");
    }
    
   return 0;
}
int reverse(int n)
{
    int x;
    int sum=0;
    while(n!=0)
    {
        x=n%10;
        sum= sum*10 + x;
        reverse(n/10);
    }
    return sum;
}