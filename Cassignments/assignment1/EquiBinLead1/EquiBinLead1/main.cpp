#include<iostream>
using namespace std;
int main()
{
	int num,j=4,i;
	int arr[6];
	cout << "enter the number between 0 and 32 ";
	cin >> num;
	while (num != 0)
	{
		arr[j] = num % 2;
		num = num / 2;
		j--;
	}
	while (j>=1)
	{
		arr[j--] = 0;
	}
	arr[0] = 1;
	for(i=0;i<5;i++)
	cout << arr[i];
	system("pause");
}