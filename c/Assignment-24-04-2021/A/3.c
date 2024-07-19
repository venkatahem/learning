#include <stdio.h>

void main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("\nEntered number is EVEN");
    }
    else
    {
        printf("\nEntered number is ODD");
    }
}