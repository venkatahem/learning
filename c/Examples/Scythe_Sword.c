#include <stdio.h>

void main()
{
    int i, j, tests;
    int stick[20], diamond[20];
    int swo = 0, scy = 0;
    printf("Test cases: ");
    scanf("%d", &tests);
    j = tests;
    printf("Sticks & Diamonds\n");
    for (i = 0; i < tests; i++)
    {
        printf("Sticks[%d]: ", i + 1);
        scanf("%d", &stick[i]);
        printf("Diamond[%d]: ", i + 1);
        scanf("%d", &diamond[i]);
    }
    for (i = 0; i < tests; i++)
    {
        while ((stick[i] > 0 && diamond[i] > 0) && (stick[i] > 1 || diamond[i] > 1))
        {
            if (stick[i] >= 2 && diamond[i] >= 1)
            {
                stick[i] = stick[i] - 2;
                diamond[i] = diamond[i] - 1;
                scy++;
            }

            if (stick[i] >= 1 && diamond[i] >= 2)
            {
                stick[i] = stick[i] - 1;
                diamond[i] = diamond[i] - 2;
                swo++;
            }
        }
        printf("Swords = %d\nScythes = %d\nEmrald = %d\n", swo, scy, swo + scy);
        swo = 0;
        scy = 0;
    }
}