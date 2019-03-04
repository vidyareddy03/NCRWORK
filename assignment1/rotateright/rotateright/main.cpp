#include<iostream>
using namespace std;

#define INT_BITS 32 
int rightRotate(int n, unsigned int d)
	{
		
		return (n >> d) | (n << (INT_BITS - d));
	}



int main()
{
  
	int n ;
	int d;
	cout << "enter n and d bits ";
	cin >> n >> d;
	cout << "\nRight Rotation of " << n <<
		" by " << d << " is ";
	cout << rightRotate(n, d);
	system("pause");
}