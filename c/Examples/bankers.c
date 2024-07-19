#include <stdio.h>

int main()
{
    int n = 5;
    int m = 3;
    int i, j, k, z = 0, x;
    int p[n], seq[n];
    int f;
    int alloc[5][3] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};

    int max[5][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    int avail[3] = {3, 3, 2};

    int need[5][3];
    for (i = 0; i < n; i++)
    {
        p[i] = 0;
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (p[i] == 0)
            {
                f = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                {
                    seq[z] = i;
                    z++;
                    p[i] = 1;
                    for (x = 0; x < m; x++)
                        avail[x] = avail[x] + alloc[i][x];
                }
            }
        }
    }

    f = 0;
    for (i = 0; i < n; i++)
    {
        if (p[i] == 0)
        {
            printf("\nThe system is not safe.");
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        printf("\nThe system is safe.");
        printf("\nSafe Sequence:\n");
        printf("<");
        for (i = 0; i < n; i++)
            printf(" P%d , ", seq[i]);
        printf(">\n");
    }
    return 0;
}
