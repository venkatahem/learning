#include <stdio.h>

void main()
{
    int a, b;
    printf("Enter the two number:\n");
    scanf("%d%d", &a, &b);
    if (a % b == 0)
    {
        printf("\n%d is divisible by %d\n", a, b);
    }
    else
    {
        printf("\n%d is not divisible by %d\n", a, b);
    }
}