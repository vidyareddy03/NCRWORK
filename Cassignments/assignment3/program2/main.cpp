#include<iostream>
using namespace std;
int main()
{
	int arr[10],newarr[10], i,size,temp,j=0;
	cout << "enter the size of an array ";
	cin >> size;
	for (i = 0; i < size; i++)
		cin >> arr[i];
	for (i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			newarr[j++] = arr[i];
			arr[i] = 0;
		}
		
	}
	for (i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		else
			newarr[j++] = arr[i];
	}
	for (i = 0; i < j; i++)
		cout << newarr[i] << " ";
	system("pause");
}