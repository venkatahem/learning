#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int *arr, int *left, int l, int *right, int r)
{
    int i, j, k;
    i = j = k = 0;
    while (i < l && j < r)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < l)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < r)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int n)
{
    if (n < 2)
    {
        return;
    }
    else
    {
        int mid = n / 2;
        int i;

        int *left = (int *)malloc(mid * (sizeof(int)));
        int *right = (int *)malloc((n - mid) * sizeof(int));

        for (i = 0; i < mid; i++)
        {
            left[i] = arr[i];
        }
        for (i = mid; i < n; i++)
        {
            right[i - mid] = arr[i];
        }

        // cout << "\n\n0)\nLeft: ";
        // for (i = 0; i < mid; i++)
        // {
        //     cout << left[i] << "  ";
        // }
        // cout << "\nRight: ";
        // for (i = 0; i < n - mid; i++)
        // {
        //     cout << right[i] << "  ";
        // }
        // cout << "\nArray: ";
        // for (i = 0; i < n; i++)
        // {
        //     cout << arr[i] << "  ";
        // }

        mergeSort(left, mid);
        mergeSort(right, n - mid);
        merge(arr, left, mid, right, n - mid);
        // cout << "\n\n1)\nLeft: ";
        // for (i = 0; i < mid; i++)
        // {
        //     cout << left[i] << "  ";
        // }
        // cout << "\nRight: ";
        // for (i = 0; i < n - mid; i++)
        // {
        //     cout << right[i] << "  ";
        // }
        // cout << "\nArray: ";
        // for (i = 0; i < n; i++)
        // {
        //     cout << arr[i] << "  ";
        // }

        free(left);
        free(right);
    }
}

int main()
{
    int arr[] = {6, 8, 1, 5, 33, 9, 4, 21, 90, 54, 23, 45, 68, 12, 21, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    // cout << size;
    cout << "Initial(unsorted):\n";
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }

    mergeSort(arr, size);

    cout << "\nSorted:\n";
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
    return 0;
}