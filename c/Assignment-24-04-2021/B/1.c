#include <stdio.h>

void main()
{
    int cost, sell;
    printf("Enter the cost of the product: ");
    scanf("%d", &cost);
    printf("Enter the selling price: ");
    scanf("%d", &sell);
    if (cost > sell)
    {
        printf("\nThe product is sold for a loss\n");
    }
    else if (sell > cost)
    {
        printf("\nThe product is sold for a profit\n");
    }
}