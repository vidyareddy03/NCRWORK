#include<stdio.h>
#include<iostream>
using namespace std;
void strcopy(char *s2, char *s1)
{
	while ((*s2 = *s1) != '\0')
	{
		s1++;
		s2++;
	}
	*s2 = '\0';
	printf("copied string is %s", s2);
	cout <<endl<< s2<<endl;
}
void strconcate(char *s1, char *s2)
{
	
	while (*s1++ != '\0');
	while ((*s1++ = *s2++) != '\0');
	*s1 = '\0';
	printf("concatinated string %s", s1);
}
void main()
{
	char *s1,*s2;
	int len,len1;
	printf("enter the length of string ");
	cin >> len;
	s1 = new char[len];
	cout << "enter the string to be copied ";
	cin >> s1;
	//gets(s1);
	s2 = new char[len];
	strcopy(s2, s1);
	cout << "enter the length of string to be concatinated ";
	cin >> len1;
	s2 = new char[len + len1];
	printf("enter string to be concatinated ");
	cin >> s2;
	strconcate(s1, s2);
	system("pause");
}