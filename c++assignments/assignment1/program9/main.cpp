#include<iostream>
using namespace std;

void call_value(int n1,int n2)
{
	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;
	cout << "in function......";
	cout << n1 << " " << n2 << endl;
}

void call_reference(int &n1, int &n2)
{
	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;
	cout << "in function......";
	cout << n1 << " " << n2 << endl;
}
void main()
{
	int n1, n2;
	int choice;
	cout << "enter the two numbers " << endl;
	cin >> n1 >> n2;
	cout << "choose the choice " << endl << "1. call by value" << endl << "2. call by reference" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: cout << "before swaping by call by value "<<n1<<" "<<n2<<endl;
		call_value(n1, n2);
		cout << "after swaping by call by reference " << n1 << " " << n2 << endl;
		break;
	case 2: cout << "before swaping by call by value " << n1 << " " << n2 << endl;
		call_reference(n1, n2);
		cout << "after swaping by call by reference " << n1 << " " << n2<<endl;
		break;
	default: cout << "wrong choice" << endl;
		break;
	}
	system("pause");
}