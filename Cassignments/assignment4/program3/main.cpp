#include<iostream>
using namespace std;
int main()
{
	int i,j,count=0;
	char *s[] = { "we will teach you how to ", "Move a mountain","Level a building","Erase the past","Make a million"};
	for (i = 0; i < 5; i++)
	{
		for (j = 0; s[i][j] != '\0'; j++)
		{
			if (s[i][j] == 'e')
				count++;
		}
	}
	cout << "no of e's is " << count<<endl;
	system("pause");
}