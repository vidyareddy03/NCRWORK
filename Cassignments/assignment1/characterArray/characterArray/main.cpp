#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int i,k,j, t,l=0,d=0,a=0,s=0,tc=0;
	char text[80];
	cin.getline(text, sizeof(text));
	l = strlen(text);

	for (i = 0;i<l;)
	{
		if (isdigit(text[i]))
		{
			d++;
			i++;
			
		}
		else if (isalpha(text[i]))
		{
			a++;
			i++;
			
		}
		else if (isspace(text[i]))
		{
			k = i+1;
			t = 1;
			for (j = 0; j < 5; j++)
			{
				if (isspace(text[k++]))
				{
					t++;
				}
				else
				{
					break;
				}
			}
			if (t == 6)
				tc++;
			else
			{
				s = s+t;
			
			}
			t = 0;
			i = k-1;
		}
	}
	cout << "alphbets=" << a << endl;
	cout << "digits=" << d << endl;
	cout << "spaces=" << s-tc<< endl;
	cout << "tab space=" << tc << endl;
	system("pause");
}