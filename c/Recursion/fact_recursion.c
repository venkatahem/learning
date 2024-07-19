#include <stdio.h>
int fact(int);
int main()
{
    int n,f;
    printf("Enter a number: ");
    scanf("%d",&n);
    f=fact(n);
    printf("%d",f);

    return 0;
}
int fact(int n)
{
    int res;
    if(n==0)
    {
    res=1;
    }
    else
    {
        res=n*fact(n-1);
    }
    return res;
    
}