#include<iostream>
#include<string.h>
using namespace std;

int replace(char *cat,int len)
{
	int i,n=0;
	for (i = 0; i <= len; i++)
	{
		if (cat[i] == ' ')
		{
			cat[i] = '-';
			n++;
		}
	}
	return n;
}
int main()
{
	char str[] = "The cat sat";
	char *cat = NULL;
	int n;
	cat = (char *)malloc(12 * sizeof(char));
	cat = str;
	n = replace(cat,strlen(cat));
	cout <<endl<< cat << endl << n;
	system("pause");
}