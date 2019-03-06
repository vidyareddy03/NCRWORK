/* app for demo library*/
#include<iostream>
#include<Windows.h>
#include"demo1.h"
using namespace std;
int main()
{
	int n1, n2, choice;
	cout << "enter two numbers ";
	cin >> n1 >> n2;
	cout << "1.add 2.sub 3.mul 4.div " << endl << "enter the choice ";
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "sum is " << add(n1, n2);
		break;
	case 2:cout << "sub is " << sub(n1, n2);
		break;
	case 3: cout << "mul is " << mul(n1, n2);
		break;
	case 4:cout << "div is " << divv(n1, n2);
		break;
	default:cout << "entered the wrong choice ";
	}
	system("pause");
}