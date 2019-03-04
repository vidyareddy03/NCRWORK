#include<iostream>
using namespace std;
class Time 
{
	int hh, mm, sec;
public:
	Time()
	{
		hh = mm = sec = 00;
	}
	Time(int h,int m, int s )
	{
		hh = h;
		mm = m;
		sec = s;
	}
	void display()
	{
		cout <<endl<< hh<<":" << mm<<":" << sec;
	}
	void add(Time &t2, Time &t3)
	{
		sec = t2.sec + t3.sec;
		mm = t2.mm + t3.mm;
		hh = t2.hh + t3.hh;
	}
};
void main()
{
	Time t1,t2(2,00,00),t3(10,50,40);
	t1.display();
	t2.display();
	t3.display();
	t1.add(t2, t3);
	t1.display();
	system("pause");

}