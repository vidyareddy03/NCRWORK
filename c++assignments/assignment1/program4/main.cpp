#include<iostream>
using namespace std;
inline void add(float x, float y)
{
	cout << "sum is " << x + y << endl;
}
inline void sub(float x, float y)
{
	cout << "sub is " << x - y << endl;
}
inline void mul(float x, float y)
{
	cout<<"mul is "<< x * y<<endl;
}
inline void div(float x, float y)
{
	cout<<"div is "<< x / y<<endl;
}

void main()
{
	float x, y;
	cout << "enter two numbers ";
	cin >> x >> y;
	add(x, y);
	sub(x, y);
	mul(x, y);
	div(x, y);

	system("pause");

}

