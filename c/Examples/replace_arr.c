#include <stdio.h>

int main()
{
    int arr[10],a,b,c=0,d,i,n=0;

    printf("Enter a number: ");
    scanf("%d",&a);
    d=a;
    while(d!=0)
    {
        b = d;
        c = c*10 + b;
        d = d/10;
    }
    
}