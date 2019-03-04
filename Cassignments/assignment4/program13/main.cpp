#include<stdio.h>
#include<iostream>

#define MAXLINE 100
using namespace std;


void expand(char *s1, char *s2);

int main(void)
{
	
	int n,count,i,j;
	char *S1, *S2;
	cout<<"enter the size of string ";
	cin >> n;
	S1 = new char[n];
	count = 0;
	cout << "enter the shorthand string ";
	cin >> S1;
	for (i = 0; S1[i] != '\0'; i++)
	{
		if (S1[i] == '-')
		{
			for (j = S1[i - 1] + 1; j < S1[i + 1]; j++)
			{
				count++;
			}
			i++;
		}
		count++;

	}
	S2 = new char[count];
	expand(S1,S2);
	cout << S2<<endl;
	system("pause");
	
	delete S1;
	delete S2;
	//getchar();
	return 0;
}



void expand(char *s1, char *s2)
{
	int i, j, c;

	i = j = 0;

	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i + 1] >= c)
		{
			i++;
			while (c<s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;

	s2[j] = '\0';
}
