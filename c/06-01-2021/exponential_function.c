#include <stdio.h>
int b;
int expo(int);
int main()
{
    int p,v;
    printf("Enter the base: ");
    scanf("%d",&b);
    printf("Enter the power: ");
    scanf("%d",&p);
    v=expo(p);
    printf("%d",v);

    return 0;
}
int expo(int p)
{
    static int a=1;
    if(p!=0)
    {
        a=a*b;
        expo(p-1);
    }
    return a;
}