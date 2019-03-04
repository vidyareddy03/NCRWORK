#include <stdio.h>
#include <string.h>
#include<iostream>
#include<string>
using namespace std;
void main()
{

	char name[10][10], temp[10];
	int i, j, n;
	
	cout<<"Enter the value of n ";
	cin >> n;
	cout << "enter the names ";

	for (i = 0; i < n; i++)
	{
		cin >> name[i];
		
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(name[i], name[j]) > 0)
			{
				strcpy_s(temp, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp);
			}
		}
	}

	cout << "sorted names are "<<endl;

	for (i = 0; i < n; i++)
	{
		
		cout << name[i] << endl;
	}

	system("pause");

}