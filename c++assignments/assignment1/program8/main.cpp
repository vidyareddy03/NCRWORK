#include<iostream>
using namespace std;
class Employee
{
	int x;
	float y;
public:

	Employee()
	{
		cout << "default constructor"<<endl;
	}
	Employee(int x)
	{
		cout << "parameter constructor call by value"<<endl;
	}
	Employee(Employee &x)
	{
		cout <<"parameter constructor call by reference"<<endl;
	}
};
void main()
{
	Employee e1, e2(4), e3(e2);
	cout << "size is " << sizeof(e1) << endl << sizeof(e2);
	system("pause");
}