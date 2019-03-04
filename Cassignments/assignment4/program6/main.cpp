#include<iostream>
using namespace std;

void reverse(char *str)
	{
		if (*str)
		{
			reverse(str + 1);
			printf("%c", *str);
		}
	}

int main()
{
	char str[10];
	cin.getline(str, 10);
	reverse(str);
	system("pause");
}