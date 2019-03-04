#include<iostream>
using namespace std;
int main()
{
	int num, rem, n, rev;
	cout << "enter number";
	cin >> num;
	n = num;
	rev = 0;
	while(num!=0)
	{
		rem = num % 10;
		rev = (rev * 10) + rem;
		num = num / 10;
	}
	if (n == rev)
		cout << "palindrome number";
	else
		cout << "not a palindrome number";
	system("pause");
}