#include <stdio.h>
#include <conio.h>

void matrixInput(int mat[][3]);
void matrixPrint(int mat[][3]);
void matrixAdd(int mat1[][3], int mat2[][3], int res[][3]);

int main()
{
    int mat1[3][3], mat2[3][3], res[3][3];

    printf("Enter elements in first matrix of size 3x3: \n");
    matrixInput(mat1);
    printf("\nEntered matrix\n");
    matrixPrint(mat1);

    printf("\nEnter elemetns in second matrix of size 3x3 \n");
    matrixInput(mat2);
    printf("\nEntered matrix\n");
    matrixPrint(mat1);

    matrixAdd(mat1, mat2, res);

    printf("\nSum of first and second matrix: \n");
    matrixPrint(res);
    
    return 0;
}
void matrixInput(int mat[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
          scanf("%d", (*(mat + i) + j));
        }
    }
}
void matrixPrint(int mat[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
void matrixAdd(int mat1[][3], int mat2[][3], int res[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            *(*(res + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}