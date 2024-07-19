#include <stdio.h>
float power(int,int);
int main()
{
    int x;
    int a;
    float b;
    printf("Enter the base number: ");
    scanf("%d",&x);
    printf("Enter the power: ");
    scanf("%d",&a);
    b=power(x,a);
    printf("\n%d to the power of %d is %f\n",x,a,b);

    return 0;
}
float power(int x,int a)
{
    float p=1;
    for(int i=0;i<a;i++)
    {
        p=p*x;
    }
    return p;
}