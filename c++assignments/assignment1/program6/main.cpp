#include<iostream>
using namespace std;
class Point
{
	float x, y;
public:
	Point(int i, int j) {
		x = i;
		y = j;
	}
	friend void add(Point obj, Point obj2);
};

void add(Point obj1, Point obj2)
{
	int xx = pow((obj1.x-obj2.x),2);
	int yy= pow((obj1.y - obj2.y), 2);
	int dis = sqrt((xx + yy));
	cout << "distance is " << dis << endl;
}

void main()
{
	Point o1(5, 6), o2(9, 9);
	add(o1, o2);
	system("pause");
}
