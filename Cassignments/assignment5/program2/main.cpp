#include<iostream>
using namespace std;
struct size1
{
	int n;
	char x;
}s1;
union size2
{
	int n2;
	char x2;
}s2;
void main()
{
	cout << "size of structure is " << sizeof(s1)<<endl;
	cout << "size of unoin is " << sizeof(s2) << endl;
	system("pause");
}