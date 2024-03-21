#include <iostream>
using namespace std;
int binarySearch(int low, int high, int arr[], int k)
{
	if (low > high)
	{
		return -1;
	}
	int mid = (low + (high - low)) / 2;
	if (arr[mid] == k)
	{
		return mid;
	}
	else if (arr[mid] > k)
	{
		return binarySearch(mid + 1, high, arr, k);
	}
	else
	{
		return binarySearch(low, mid - 1, arr, k);
	}
}
void find(int n, int k, int arr[])
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(arr[i], arr[minIndex]);
		}
	}
	int res = binarySearch(0, n, arr, k);
	if (res == -1)
	{
		cout << "The Key not found!!!" << endl;
		return;
	}
	cout << k << " is Found at " << res << endl;
}
int main()
{
	int n, k;
	cout << "Enter the size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter Elements into array: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the key to search: ";
	cin >> k;
	find(n, k, arr);
	return 0;
}
