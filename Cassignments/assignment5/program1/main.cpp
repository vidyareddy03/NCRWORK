#include<iostream>
using namespace std;
struct time
{
	int hh, mm, sec;
};

void main()
{
	struct time t1;
	t1.hh = 10;
	t1.mm = 45;
	t1.sec = 20;
	cout << "time is " << t1.hh << ":" << t1.mm << ":" << t1.sec << endl;
	system("pause");
	
}