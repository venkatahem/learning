#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int front;
    int rear;
    int mid;
    front = 0;
    rear = n;
    while (front <= rear)
    {
        mid = (front + rear) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            front = mid + 1;
        }
        else
        {
            rear = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int i;
    int n;
    int key;
    cout << "Size:";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Key: ";
    cin >> key;

    cout << binarySearch(arr, n, key);

    return 7;
}