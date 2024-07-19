#include <stdio.h>

void main()
{
    int a, b, c;

    printf("Enter the sales amount: ");
    scanf("%d", &a);
    if (a > 5000)
    {
        b = a / 100;
        c = b * 10;
        printf("Discount = %d and the final payable amount = %d", c, a - c);
    }
    else
    {
        b = a / 100;
        c = b * 5;
        printf("Discount = %d and the final payable amount = %d", c, a - c);
    }
}