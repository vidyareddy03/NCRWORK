#include<iostream>
using namespace std;

void selection(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n ; i++)
	{
		for (j = i + 1; j < n ; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
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
	selection(arr, n);
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	system("pause");
}