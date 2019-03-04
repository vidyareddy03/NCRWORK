#include<iostream>
using namespace std;
class stringgg
{
	char *str;
	int len;
public:
	stringgg()
	{
		str = NULL;
		len = 0;
	}
	~stringgg()
	{
		if (str != NULL)
			free(str);
	}
	stringgg(char *s)
	{
		int len = strlen(s);
		str = new char[len];
		strcpy(str, s);

	}
	stringgg(const stringgg &s)
	{
		int len = s.len;
		str = new char[len];
		strcpy(str, s.str);
	}
	void add()
	{
		cout << "hello";
	}
	 stringgg operator+(stringgg s2);
	 char operator[](int n);
	 stringgg* operator->();
	 stringgg operator=(stringgg temp);
	 friend ostream& operator<<(ostream& cout, stringgg c);
	 friend istream& operator >> (istream& cin, stringgg &s);
};

stringgg stringgg::operator+(stringgg s)
{
	stringgg s4;
	s4.len = len + s.len;
	s4 = new char[len];
	strcpy(s4.str,str);
	strcat(s4.str, s.str);
	return s4;
	
}
char stringgg::operator[](int n)
{
	return(str[n]);
}

stringgg* stringgg::operator->()
{
	return (this);
}
stringgg stringgg::operator=(stringgg temp)
{
	len = temp.len;
	if (str != NULL)
		free(str);
	str = new char[len];
	strcpy(str, temp.str);
	return (*this);
}
ostream& operator<<(ostream& cout, stringgg s)
{
	cout << "string is"<<s.str << endl;
	return (cout);

}
istream& operator >> (istream& cin, stringgg &s1)
{
	char s[50];
	cin >> s;
	if (s1.str == NULL)
		s1.str = new char[strlen(s) + 1];
	strcpy(s1.str, s);
	s1.len = strlen(s1.str);

	return (cin);

}
void main()
{
	stringgg s1("vidya"), s2, s3;
	cin >> s2;
	cout << s1 << endl << s2 << endl ;
	cout << "+"<<endl;
	s3 = s1 + s2;
	cout << "s3 is " << s3 << endl;
	s1 = s3;
	cout << "s1 is " << s1<<endl;
	cout << "s1[2] " << s1[2] << endl;
	cout << "s2->str "<<endl;
	s2->add();
	system("pause");
}
