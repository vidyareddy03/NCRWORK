#include<iostream>
#include<limits.h>
using namespace std;

int any(char s1[], char s2[])
{
	int i = 0, j = 0;

	for (i = 0; i < strlen(s1); i++) {
		for (j = 0; j < strlen(s2); j++) {
			if (s1[i] == s2[j]) {
				return i; 
			}
		}
		j = 0;
	}

	return -1;
}

int main()
{
	char s1[] = "welcome to Incredible";
	char s2[] = "ncr";
	int loc = any(s1, s2);
	if (loc == -1)
	{
		cout << "no match found " << endl;
	}
	else
		cout<<"location "<<loc<<endl;
	system("pause");
	return 0;
}

