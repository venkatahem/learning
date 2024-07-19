#include <iostream>
using namespace std;

int x = 1;
void merge(int arr[], int l, int mid, int r)
{
    cout << "\nL = " << l << " Mid = " << mid << " End = " << r << "\n";
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    int i = 0, j = 0, k;
    for (i = 0; i < n1; i++)
    {
        a[i] = arr[i + l];
    }
    for (i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    k = l;
    i = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        cout << "\n";
        cout << x << ")1)Mid: " << mid << endl;
        mergeSort(arr, l, mid);
        cout << x << ")2)Mid: " << mid << endl;
        mergeSort(arr, mid + 1, r);
        cout << x << ")3)Mid: " << mid << endl;
        merge(arr, l, mid, r);
        x++;
    }
}

int main()
{
    int arr[] = {5, 9, 6, 8, 1, 3, 4};
    int size;
    int i;
    size = sizeof(arr) / sizeof(int);

    cout << "\n\nActual array: ";
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    mergeSort(arr, 0, size - 1);
    cout << "\n\nSorted array: ";
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n\n";

    return 7;
}