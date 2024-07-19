#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int index = partition(arr, l, r);

		if (index - l == k - 1)
		{
			return arr[index];
		}

		if (index - l > k - 1)
		{
			return kthSmallest(arr, l, index - 1, k);
		}
		else
		{
			return kthSmallest(arr, index + 1, r, k - index + l - 1);
		}
	}

	return -1;
}

int main()
{
	int arr[] = {3, 8, 2, 76, 23, 9, 12, 45};
	int i;
	int n = sizeof(arr) / sizeof(int);
	int k, ele;
	cout << "Array:\n";
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\nArray size: " << n << endl;
	cout << "\n";
	cout << "Input K: ";
	cin >> k;
	ele = kthSmallest(arr, 0, n - 1, k);
	if (ele != -1)
	{
		cout << "K-th smallest element is " << ele << endl;
	}
	else
	{
		cout << "K is greater than array size" << endl;
	}
	return 0;
}
