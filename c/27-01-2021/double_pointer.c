#include <stdio.h>

int main()
{
    int x;
    int *p;
    int **dp;
    p=&x;
    dp=&p;
    printf("\nEnter a number: ");
    scanf("%d",&x);
    x=(*p)+5;
    printf("\n%d is value of x after incrementing if with 5\n",x);
    x=(*(*dp))*10;
    printf("\nAfter multiplying with 10: %d\n",x);

    return 0;
}