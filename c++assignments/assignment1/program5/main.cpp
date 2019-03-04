#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
	float meters, cm;
public:
	Distance1()
	{
		meters = 23;
		cm = 12;
	}
	friend void add(Distance1 , Distance2 );
};

class Distance2
{
	float inches, feet;
public:
	Distance2() {
		inches = 4;
		feet = 2;
	}
	friend void add(Distance1 , Distance2 );
};
void add(Distance1 d1, Distance2 d2)
{
	int m, i,choice,res;
	cout << "enter result to display in meters or inches " << endl << "1. meters" << endl << "2.inches" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: res=d1.meters + d2.inches / 39;
		cout << "in meters " << res;
		break;
	case2:
		res = d1.meters * 39 + d2.inches;
		cout << "in inches " << res;
		break;
	}
}
int main()
{
	Distance1 o1;
	Distance2 o2;
	add(o1, o2);
	system("pause");
}