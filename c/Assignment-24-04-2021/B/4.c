#include <stdio.h>

void main()
{
    int a;
    int x, y;
    printf("Choose one to find it's area\n\n1 ==> Square\n2 ==> Circle\n3 ==> Rectangle\n4 ==> Triangle\nInput: ");
    scanf("%d", &a);
    if (a == 1)
    {
        printf("\nEnter the side lenght: ");
        scanf("%d", &x);
        printf("\nArea of the square = %d Sq.units", x * x);
    }
    else if (a == 2)
    {
        printf("\nEnter the radius of the circle: ");
        scanf("%d", &x);
        y = (3.14) * x * x;
        printf("\nArea of the circle = %d Sq.units\n", y);
    }
    else if (a == 3)
    {
        printf("\nEnter the length and bredth:\n");
        scanf("%d%d", &x, &y);
        printf("\nArea of the rectangle = %d Sq.units\n", x * y);
    }
    else if (a == 4)
    {
        printf("\nEnter the height and base length:\n");
        scanf("%d%d", &x, &y);
        a = (x * y) / 2;
        printf("\nArea of the triangle = %d Sq.units\n", a);
    }
    else
    {
        printf("\nOption dosen't exsist\n");
    }
}