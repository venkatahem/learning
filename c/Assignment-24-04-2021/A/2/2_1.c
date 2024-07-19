//Area of circle
#include <stdio.h>

void main()
{
    int x, y;

    printf("\nEnter the radius of the circle: ");
    scanf("%d", &x);
    y = (3.14) * x * x;
    printf("\nArea of the circle = %d Sq.units\n", y);
}