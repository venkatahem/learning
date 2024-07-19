#include <stdio.h>

void inputMatrix(int matrix[3][3], int rows, int cols);
void printMatrix(int matrix[][3], int rows, int cols);
int main()
{
    int matrix[3][3];
    int i, j;
    printf("Enter elements in 3x3 matrix.\n");
    inputMatrix(matrix, 3, 3);
    printf("Elements of 3x3 matrix.\n");
    printMatrix(matrix, 3, 3);

    return 0;
}
void inputMatrix(int matrix[3][3], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
          scanf("%d", (*(matrix + i) + j));
        }
    }
}
void printMatrix(int (*matrix)[3], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }

        printf("\n");
    }
}
