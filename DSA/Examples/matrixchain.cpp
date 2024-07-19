#include <iostream>

#define MAX 99999999

// #define S 5

void mcm(int n, int sizes[])
{
    int costs[n][n] = {0};
    int di, row, col, i, j, k, temp;

    for (di = 1; di < n - 1; di++)
    {
        for (row = 1; row < n - di; row++)
        {
            col = di + row;
            costs[row][col] = MAX;
            for (k = row; k < col; k++)
            {
                std::cout << "\nRow: " << row << "  Col: " << col;
                temp = costs[row][k] + costs[k + 1][col] + sizes[row - 1] * sizes[k] * sizes[col];
                std::cout << "\nSum:" << temp;
                if (temp < costs[row][col])
                {
                    costs[row][col] = temp;
                }
            }
            // std::cout << "\nRow: " << row << "  Col: " << col;
        }
        // std::cout << "\nCost matrix\n";
        // for (i = 1; i < n; i++)
        // {
        //     std::cout << "\n";
        //     for (j = 1; j < n; j++)
        //     {
        //         std::cout << " " << costs[i][j] << " ";
        //     }
        // }
    }
    std::cout << "\nCost matrix\n";
    for (i = 1; i < n; i++)
    {
        std::cout << "\n";
        for (j = 1; j < n; j++)
        {
            // std::cout << " " << costs[i][j] << " ";
            printf("%7d", costs[i][j]);
        }
    }

    std::cout << "\n\nThe cost for multiplying " << n - 1 << " matrices of sizes\n";
    for (i = 0; i < n - 1; i++)
    {
        std::cout << i + 1 << ")" << sizes[i] << " x " << sizes[i + 1] << std::endl;
    }
    std::cout << "is " << costs[1][n - 1];
}

int main()
{
    int x, n, i, j;
    int size[] = {30, 25, 15, 20, 10, 5, 35};
    n = sizeof(size) / sizeof(int);
    mcm(n, size);
    return 7;
}