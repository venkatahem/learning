#include <stdio.h>

#define SIZE 2

void matrixMultiplication(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
  int n = SIZE;
  int i, j, k;
  int mul[n][n];

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      mul[i][j] = 0;
      for (k = 0; k < n; k++) {
        mul[i][j] = mul[i][j] + mat1[i][k] * mat2[k][j];
      }
    }
  }
  printf("Resultant matrix\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d  ", mul[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int i, j;
  int n = SIZE;
  int mat1[n][n];
  int mat2[n][n];

  printf("Input matrix-1 (Size - %d X %d)\n", n, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter element [%d][%d]: ", i + 1, j + 1);
      scanf_s("%d", &mat1[i][j]);
    }
  }
  printf("\nMatrix-1\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d  ", mat1[i][j]);
    }
    printf("\n");
  }
  printf("Input matrix-2 (Size - %d X %d)\n", n, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter element [%d][%d]: ", i + 1, j + 1);
      scanf_s("%d", &mat2[i][j]);
    }
  }
  printf("\nMatrix-2\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d  ", mat2[i][j]);
    }
    printf("\n");
  }

  matrixMultiplication(mat1, mat2);
}