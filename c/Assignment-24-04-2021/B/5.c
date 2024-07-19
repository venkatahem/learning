#include <stdio.h>

void main()
{
    float cel, far;
    int x;
    printf("Select\n\n1 ==> Celsius to Fahrenheit\n2 ==> Fahrenheit to Celsius\nInput: ");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("\nEnter the temperature in celsius: ");
        scanf("%f", &cel);
        far = ((cel * 9) / 5) + 32;
        printf("\n%.2f degree fahrenheit\n", far);
    }
    else if (x == 2)
    {
        printf("\nEnter the temperature in fahrenheit: ");
        scanf("%f", &far);
        cel = ((far - 32) * 5) / 9;
        printf("\n%.2f degree celsius\n", cel);
    }
    else
    {
        printf("\nInvalid option\n");
    }
}