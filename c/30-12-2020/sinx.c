#include <stdio.h>
float term_two(int);
float term_three(int);
float term_four(int);
float term_five(int);
int main()
{
    float p,q,r,s,t;
    int x;
    printf("Program to find Sin(x)\n\n");
    printf("Enter X: ");
    scanf("%d",&x);
    p=term_two(x);
    q=term_three(x);
    r=term_four(x);
    s=term_five(x);
    t=(x-p)+(q-r)+s;
    printf("\nValue of Sin(%d) is %f\n\n",x,t);

    return 0;
}
float term_two(int x)
{
    float a=1,b=1,c;
    for(int i=1;i<4;i++)
    {
        a=a*x;
        b=b*i;
    }
    c=a/b;
    return c;
}
float term_three(int x)
{
    float a=1,b=1,c;
    for(int i=1;i<6;i++)
    {
        a=a*x;
        b=i*b;
    }
    c=a/b;
    return c;
}
float term_four(int x)
{
    float a=1,b=1,c;
    for(int i=1;i<8;i++)
    {
        a=a*x;
        b=i*b;
    }
    c=a/b;
    return c;
}
float term_five(int x)
{
    float a=1,b=1,c;
    for(int i=1;i<10;i++)
    {
        a=a*x;
        b=i*b;
    }
    c=a/b;
    return c;
}