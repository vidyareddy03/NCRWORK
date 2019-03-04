#include<iostream>
using namespace std;
class Complex
{
	float real;
	float img;
public:
	Complex()
	{
		//cout << "default constructor"<<endl;
		real = img = 0;
	}
	Complex(float r)
	{
		real = img = r;
		//cout << "parameterised constructor" << endl;
	}
	Complex(Complex &c) {
		real = c.real;
		img = c.img;
		//cout << "copy constructor"<<endl;
	}
/*	~Complex()
	{
		cout << "destructor" << endl;
	}*/
	//binary +
	Complex operator+(Complex c2)
	{
		Complex res;
		res.real = real + c2.real;
		res.img = img + c2.img;
		return res;
	}
	//binary -
	Complex operator-(Complex c2)
	{
		Complex res;
		res.real = real - c2.real;
		res.img = img - c2.img;
		return res;
	}
	//unary -
	Complex operator-()
	{
		Complex res;
		res.real = -real ;
		res.img = -img ;
		return res;
	}
	//pre increment
	Complex operator++()
	{
		++real;
		++img;
		return *this;
	}
	//post increment
	Complex operator++(int x)
	{
		real++;
		img++;
		return *this;
	}
	//= operator
	Complex operator=(Complex c1)
	{
		Complex temp;
		temp.real = c1.real;
		temp.img = c1.img;
		return temp;
	}
	//, operator
	Complex operator,(Complex c)
	{
		return c;
	}
	//-> operator;
	Complex* operator->()
	{
		return this;
	}
	friend ostream& operator<<(ostream& cout, Complex c);
	friend istream& operator>>(istream& cin, Complex &s);

};
ostream& operator<<(ostream& cout, Complex s)
{
	cout << "real no is " << s.real << endl;
	cout << "img is " << s.img << endl;
	
	return (cout);

}
istream& operator>>(istream& cin, Complex &s1)
{
	cin >> s1.real;
	cin >> s1.img;
	
	return (cin);
	
}

void main()
{
	Complex c, c3, c2 ;
	//Complex *p, *s=NULL;
	cin >> c3;
	cin >> c2;
	cout << "add ";
	c = c3 + c2;
	cout << c<<endl;
	cout << " sub ";
	c = c3 - c2;
	cout << c<<endl;
	-c2;
	cout <<"-c2 " <<c2<<endl;
	c++;
	cout << c << endl;
	++c;
	cout << c<<endl;
	c = c2, c3;
	cout << c<<endl;
	c = (c2, c3);
	cout << c << endl;

	system("pause");
}

