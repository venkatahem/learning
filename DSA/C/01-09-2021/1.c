#include <stdio.h>

int main()
{
    int arr1[10] = {13, 32, 4, 5, 4, 56, 87, 43, 13, 59};
    int arr2[10] = {14, 42, 92, 7, 9, 51, 82, 69, 15, 39};
    int arr3[20];
    int i, j, len, temp;

    j = 0;
    len = sizeof(arr1) / sizeof(int);
    printf("Array - 1: ");
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr1[i]);
        if ((arr1[i] % 2) != 0)
        {
            arr3[j] = arr1[i];
            j++;
        }
    }
    len = sizeof(arr2) / sizeof(int);
    printf("\nArray - 2: ");
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr2[i]);
        if ((arr2[i] % 2) != 0)
        {
            arr3[j] = arr2[i];
            j++;
        }
    }
    printf("%d", j);
    printf("\nFinal array: ");
    for (i = 0; i < j; i++)
    {
        printf("%d  ", arr3[i]);
    }

    return 7;
}