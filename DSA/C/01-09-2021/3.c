#include <stdio.h>

int main()
{
    int teams[2][3] = {{11, 35, 12}, {14, 45, 18}};
    int cost[3] = {2000, 100, 1000};
    int total_cost[2];
    int i, j, k, sum, temp;

    for (i = 0; i < 2; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum = sum + teams[i][j] * cost[j];
        }
        total_cost[i] = sum;
    }
    printf("Total cost of equipment purchased by women's team: %d\n", total_cost[0]);
    printf("Total cost of equipment purchased by men's team: %d", total_cost[1]);

    return 7;
}