#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	char **names;
    char name[10];
	int n,i,len;
	
	cout << "enter the number of names ";
	cin >> n;
	names = (char **)malloc(sizeof(char *)*n);
	cout << "enter the names ";
	for (i = 0; i < n; i++)
	{
		cin >> name;
		len = strlen(name);
		names[i] = (char *)malloc((len) * sizeof(char));
		strcpy_s(names[i], name);
		
	}
	for (i = 0; i, n; i++)
	{
		cout << names[i];
		free(names[i]);
	}
	free(names);
	
	system("pause");

}