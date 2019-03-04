#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float amount = 500000;
	float si = 0,r=3.5/100;
	si = (500000 *3.5 * 10) / 100;
	cout << "simple interest if rate is 10 is " << si;
	cout << endl << "compound interest anually is " << amount*pow((1 + r), 10);
	cout << endl << "compound interest semi-anually is " << amount*pow((1 + (r)*2), 5);
	cout << endl << "compound interest quaterlly is " << amount*pow((1 + (r)*4), (10/4));
	cout << endl << "compound interest monthly is " << amount*pow((1 + (r) / 12), (10 *12));
	cout << endl << "compound interest daily is " << amount*pow((1 + (r)/365), (10 * 365));
	system("pause");

}