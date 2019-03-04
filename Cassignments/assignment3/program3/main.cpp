#include<iostream>
using namespace std;
int main()
{
	long int num;
	int count = 0;
	cout << "enter 8 bit number ";
	cin >> num;
	while (num != 0)
	{
		if (num % 10 == 1)
		{
			count++;
		}
		num = num / 10;
	}
	cout << "number of 1's are " << count<<endl;
	system("pause");
}