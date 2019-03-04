#include<iostream>
using namespace std;
void bubble(int arr[],int n)
{
	int i, j, temp, flag = 0;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void main()
{
	int arr[15];
	int n,i;
	cout << "enter the size of array ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	bubble(arr,n);
	for (i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}

	system("pause");
}