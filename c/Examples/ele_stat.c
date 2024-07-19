#include <stdio.h>

void main()
{
    float E,q1,q2,r,a,b;
    printf("\nEnter q1: ");
    scanf("%f",&q1);
    printf("\nEnter q2: ");
    scanf("%f",&q2);
    printf("\nEnter r: ");
    scanf("%f",&r);
    a = q1*q2;
    b = (4)*(3.14)*(2)*r*r;
    E = a/b;
    printf("%f",E);
}