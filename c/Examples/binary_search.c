#include <stdio.h>
int main()
{
    int arr[] = {23, 435, 65, 67, 71, 799, 787, 8, 7, 65, 60, 646, 4, 64, 6, 53, 2, 452, 45, 45, 642, 34, 14, 134, 14};
    int i;
    int j;
    int temp;
    int size;
    int low, mid, high;
    size = sizeof(arr) / sizeof(int);
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("%d\n", size);
    temp = 642;
    low = 0;
    high = size - 1;
    mid = (high + low) / 2;
    while (1)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == temp)
        {
            printf("%d --> %d", temp, mid);
            break;
        }
        else if (arr[mid] > temp)
        {
            high = mid - 1;
        }
        else if (arr[mid] < temp)
        {
            low = mid + 1;
        }
    }

    return 0;
}