#include<iostream>
using namespace std;
class Polar
{
	int angle, radius;
public:
	static int count;
	Polar()
	{
		angle = 30;
		radius = 5;
		count++;
		//cout << "active objects are " << count;
	}
	Polar(int an,int rad) {
		angle = an;
		radius = rad;
		count++;
	}
	~Polar() {
		count--;
	}

};
int Polar:: count = 0;
void main()
{
	Polar p1, p2, p3, p4(30,6);
	cout << "number of active objects are " << Polar::count<<endl;
	system("pause");
}