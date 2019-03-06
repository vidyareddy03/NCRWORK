#include<stdio.h>
#include<iostream>
#include "E:\NCRWork\WindowsInternals\DLL\static23\static23.h"
using namespace std;
int main()
{
	double a, b;
	cout << "enter two numbers ";
	cin >> a >> b;
	cout << "sum of " << a << " and " << b << " is " << Mathfun::add(a, b)<<endl;
	cout << "sub of " << a << " and " << b << " is " << Mathfun::sub(a, b)<<endl;
	cout << "mul of " << a << " and " << b << " is " << Mathfun::mul(a, b)<<endl;
	cout << "div of " << a << " and " << b << " is " << Mathfun::div(a, b)<<endl;
	system("pause");
}