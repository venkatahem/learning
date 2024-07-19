#include <stdio.h>
int lin_equ(int,int,int);
int main()
{
    int x,y,z;
    float A;
    printf("Program to find the value of A in the linear Equation AX(1)+X(2)+X(3)=0\n\n");
    printf("Enter the value of X(1): ");
    scanf("%d",&x);
    printf("Enter the value of X(2): ");
    scanf("%d",&y);
    printf("Enter the value of X(3): ");
    scanf("%d",&z);
    A=lin_equ(x,y,z);
    printf("The value of A is %f",A);

    return 0;
}
int lin_equ(int x,int y,int z)
{
    float b;
    int a;
    a=(-y-z);
    b=a/x;
    return b;
}
