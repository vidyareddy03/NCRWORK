#include<iostream>
using namespace std;
int main()
{
	float sal,gross_sal=0;
	cout << "enter the base salary ";
	cin >> sal;
	if (sal >= 1 && sal <= 4000)
	{
		gross_sal = sal + (sal / 10) + (sal / 2);
	}
	else if (sal >= 4001 && sal <= 8000)
	{
		gross_sal = sal + (sal / 5) + ((3 * sal) / 5);
	}
	else if (sal >= 8001 && sal <= 12000)
	{
		gross_sal = sal + (sal / 4) + ((7 * sal) / 10);
	}
	else
	{
		gross_sal = sal + ((3 * sal) / 10) + ((4 * sal) / 5);
	}
	cout << "gross salary is " << gross_sal<<endl;
	system("pause");

}