#include <iostream>
#include <stdlib.h>

using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int partIndex = start;
    int i;
    for (i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[partIndex];
            arr[partIndex] = temp;
            partIndex++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[partIndex];
    arr[partIndex] = temp;
    return partIndex;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int partIndex = partition(arr, start, end);
        quickSort(arr, start, partIndex - 1);
        quickSort(arr, partIndex + 1, end);
    }
}

int main()
{
    int arr[] = {5, 8, 2, 4, 1, 9, 2, 10, 6, 7};
    int size, i;

    size = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, size - 1);
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}