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
	friend ostream& operator<<(ostream& cout, stringgg c);
};
ostream& operator<<(ostream& cout, stringgg s)
{
	cout << "string is" << s.str << endl;
	return (cout);

}

void main()
{
	stringgg s1("vidya"), s2(s1);
	cout << s2;
	system("pause");
}