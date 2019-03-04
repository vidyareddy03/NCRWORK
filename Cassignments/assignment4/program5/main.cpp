#include<iostream>
#include<ctype.h>
using namespace std;
int main()
{
	char s[20];
	int i;
	cout << "enter the strng ";
	cin.getline(s, 20);
	for (i = 0; s[i] != '\0'; i++)
	{
		printf("%c", tolower(s[i]));
	}
	cout << endl;
	for (i = 0; s[i] != '\0'; i++)
	{
		printf("%c", toupper(s[i]));

	}

	system("pause");
}