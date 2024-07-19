#include <stdio.h>

void main()
{
    int a, n;
    printf("Enter a number(n): ");
    scanf("%d", &n);
    a = 1;
    printf("\nNatural numbers from 1 to %d\n", n);
    while (a < (n + 1))
    {
        printf("%d  ", a);
        a++;
    }
}