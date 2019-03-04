#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;

}
int partition(int a[], int low, int high)
{
	int l, r, pivot, flag, temp;
	l = low;
	r = high;
	pivot = low;
	flag = 0;
	while (flag == 0)
	{
		while ((a[pivot] <= a[r]) && (pivot != r))
			r--;
		if (pivot == r)
			flag = 1;
		else if (a[pivot] > a[r])
		{
			swap(a[pivot], a[r]);
			pivot = r;
		}
		if (flag == 0)
		{
			while ((a[pivot] >= a[l]) && (pivot != l))
				l++;
			if (pivot == l)
				flag = 1;
			else if (a[pivot] < a[l])
			{
				swap(a[pivot], a[l]);
				pivot = l;
			}
		}
	}
	return pivot;
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << endl;
}


int main()
{
	int n,i;
	int arr[20];
	cout << "enter the size of an array ";
	cin >> n;
	// = new int[n];
	cout << "enter the elements ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	quickSort(arr, 0, n - 1);
	cout << "sorted array is " << endl;
	printArray(arr, n);
	//delete arr;
	system("pause");
	return 0;
}

