#include <stdio.h>
int main()
{
    float r;
    float area,circum;
    printf("Enter the radius of the circle: ");
    scanf("%f",&r);
    area = (3.14)*(r*r);
    circum = 2*(3.14)*r;
    printf("\nArea of the cirle is %.3f\ncircumference of the circle is %.3f\n",area,circum);

    return 0;
}