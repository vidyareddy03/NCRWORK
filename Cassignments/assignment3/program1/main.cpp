#include<iostream>
using namespace std;
int main()
{
	int arr[10],i,j,size,sum,temp=0,flag=0;
	cout << "enter the size of an array ";
	cin >> size;
	for (i = 0; i < size; i++)
		cin >> arr[i];
	cout << endl << "enter the sum ";
	cin >> sum;
	for (i = 0; i < size; i++)
	{
		temp = arr[i];
		for (j = i + 1; j < size; j++)
		{
			temp += arr[j];
			if (temp == sum)
			{ 
				flag = 1;
				break;
			}
			else if (temp > sum)
			{
				break;
			}
		}
		if (flag == 1)
		{
			cout << endl << "sum found between indexes " << i << " and " << j<<endl;
			break;
		}
		

	}
	system("pause");

}