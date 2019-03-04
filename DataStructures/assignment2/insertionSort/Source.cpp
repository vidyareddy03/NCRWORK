#include<iostream>
using namespace std;
void insertion(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && (arr[j]>temp); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void main()
{
	int arr[15];
	int n, i;
	cout << "enter the size of array ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	insertion(arr, n);
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	system("pause");
}