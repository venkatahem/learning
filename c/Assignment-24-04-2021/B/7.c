#include <stdio.h>
#include <math.h>

void main()
{
    int a, b, c;
    float dis;
    float r, root1, root2, sq;
    printf("\nEnter the co-eff of x^2: ");
    scanf("%d", &a);
    printf("\nEnter the co-eff of X: ");
    scanf("%d", &b);
    printf("\nEnter the constant: ");
    scanf("%d", &c);
    dis = (b * b) - 4 * (a * c);
    printf("\nDiscriminant = %f", dis);
    if (dis == 0)
    {
        printf("\nThe roots are real and equal\n");
        r = (-b) / (2 * a);
        printf("The root is X = %f\n", r);
    }
    else if (dis > 0)
    {
        printf("\nThe roots are real and different\n");
        sq = sqrt(dis);
        root1 = ((-b) + sq) / (2 * a);
        root2 = ((-b) - sq) / (2 * a);
        printf("\nThe roots are %f and %f\n", root1, root2);
    }
    else if (dis < 0)
    {
        printf("\nRoots are imaginary\n");
        dis = (-1 * dis);
        sq = sqrt(dis);
        a = 2 * a;
        if (b < 0)
        {
            b = (-1 * b);
            printf("\nRoots are %d + i(%f))/(%d)\n", b, sq, a);
            printf("\nRoots are %d - i(%f))/(%d)\n", b, sq, a);
        }
        else
        {
            printf("\nRoots are (-%d + i(%f))/(%d)\n", b, sq, a);
            printf("\nRoots are (-%d - i(%f))/(%d)\n", b, sq, a);
        }
    }
}