#include <stdio.h>

void main()
{
    int x;
    printf("Enter a day-number to print the corresponding day: ");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        printf("\nSunday");
        break;
    case 2:
        printf("\nMonday");
        break;
    case 3:
        printf("\nTuesday");
        break;
    case 4:
        printf("\nWednesday");
        break;
    case 5:
        printf("\nThursday");
        break;
    case 6:
        printf("\nFriday");
        break;
    case 7:
        printf("\nSaturday");
        break;
    }
}