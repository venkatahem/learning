#include <stdio.h>

int main()
{
    int bowls[][2] = {{2, 5}, {4, 3}, {3, 7}, {5, 8}, {9, 6}, {11, 11}};
    int i, j, k, temp1, temp2, len;

    len = (sizeof(bowls) / sizeof(int)) / 2;
    for (i = 0; i < (len - 1); i++)
    {
        if (bowls[i][0] > bowls[i + 1][0])
        {
            temp1 = bowls[i][0];
            temp2 = bowls[i][1];
            bowls[i][0] = bowls[i + 1][0];
            bowls[i][1] = bowls[i + 1][1];
            bowls[i + 1][0] = temp1;
            bowls[i + 1][1] = temp2;
        }
    }
    k = 1;
    for (i = 0; i < (len - 1);)
    {
        if ((bowls[i][0] < bowls[i + 1][0]) && (bowls[i][1] < bowls[i + 1][1]))
        {
            printf("[%d, %d]\n", bowls[i][0], bowls[i][1]);
            printf("[%d, %d]\n", bowls[i + 1][0], bowls[i + 1][1]);
            printf("-------\n");
            k++;
            i++;
        }
        else
        {
            for (j = (i + 1); j < len; j++)
            {
                if ((bowls[i][0] < bowls[j + 1][0]) && (bowls[i][1] < bowls[j + 1][1]))
                {
                    printf("[%d, %d]\n", bowls[i][0], bowls[i][1]);
                    printf("[%d, %d]\n", bowls[j + 1][0], bowls[j + 1][1]);
                    printf("-------\n");
                    k++;
                    i = (j + 1);
                }
            }
        }
    }
    printf("Max no.of bowls: %d", k);

    return 7;
}