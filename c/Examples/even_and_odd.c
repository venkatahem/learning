#include <stdio.h>

int main()
{
    int A[20], B[20], C[20];
    int x, y, i, j;
    printf("Enter the size of array: ");
    scanf("%d", &y);
    printf("Enter the numbers:\n");
    for (x = 0; x < y; x++)
    {
        scanf("%d", &A[x]);
    }
    i = 0;
    j = 0;
    for (x = 0; x < y; x++)
    {
        if (A[x] % 2 == 0)
        {
            C[i] = A[x];
            i++;
        }
        else
        {
            B[j] = A[x];
            j++;
        }
    }
    printf("Even numbers:\n");
    for (x = 0; x < i; x++)
    {
        printf("%d  ", C[x]);
    }
    printf("\n");
    printf("Odd numbers:\n");
    for (x = 0; x < j; x++)
    {
        printf("%d  ", B[x]);
    }
}