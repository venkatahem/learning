#include <stdio.h>
int count_zeros(int);
int main()
{
    int n,x;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("No.of zeroes are 1 in %d",n);
    }
    else
    {
        x=count_zeros(n);
        printf("No.of zeros in %d is/are %d",n,x);
    }
    
    return 0;
}
int count_zeros(int n)
{
    static int count=0;
    int a=0;
    if(n!=0)
    {
        a=n%10;
        if(a==0)
        {
            count++;
        }
        count_zeros(n/10);
    }    
    
    return count;
}