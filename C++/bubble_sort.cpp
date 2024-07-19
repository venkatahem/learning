#include <iostream>

using namespace std;

int main()
{
    int i;
    int n;
    int temp;
    int count;
    cout << "Size:";
    cin >> n;
    int arr[n];
    cout << "Array input: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    count = 1;
    while (count < n)
    {
        // cout << "\nCount: " << count;
        // cout << "\n\n";
        for (i = 0; i < (n - count); i++)
        {
            // cout << "\nArr[i]: " << arr[i];
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        count++;
    }
    cout << "\n\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    return 7;
}