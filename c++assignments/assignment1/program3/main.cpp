#include<iostream>
using namespace std;

class Complex
{
	float real, img;
public:
	Complex()
	{
		cout << "this is default constructor"<<endl;
		real = img = 0;

	}
	Complex(float num)
	{
		real = img = num;
		cout << "this is a constructor with one parameter" << endl;
	}
	Complex(float r, float i)
	{
		cout << "this is a constructor with 2 parameters" << endl;
		real = r;
		img = i;
	}
	friend void add(Complex &c1, Complex &c2)
	{
		cout << "sum of real is " << c1.real + c2.real<<endl;
		cout << "sum of imaginary is " << c1.img + c2.img << endl;
	}
	friend void mul(Complex &c1, Complex &c2);
};

void mul(Complex &c1, Complex &c2)
{
	cout << "mul of real is " << c1.real*c2.real << endl;;
	cout << "mul of img is " << c1.img*c2.img<<endl;

}
int main()
{
	Complex c, c1(5), c2(6, 7);
	add(c1, c2);
	mul(c1, c2);
	
	system("pause");
}