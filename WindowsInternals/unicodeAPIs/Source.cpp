#include<Windows.h>
#include<iostream>
using namespace std;

void _tmain()
{
	CHAR c[] = "hello";
	WCHAR c1[] = L"cool";

	cout << c << endl;
	wcout<<c1 << endl;//cout wide char gives unicode value
	printf("%s\n", c);
	printf("%S\n", c1);
	int un1,ret;
	// testing unicode or not
	un1 = IsTextUnicode(c, strlen(c), NULL);
	if (un1 == 0)
		cout << "c is not an unicode " << endl;
	else
		cout << "c is an unicode " << endl;
	un1 = IsTextUnicode(c1, wcslen(c1), NULL);
	if (un1 == 0)
		cout << "c1 is not an unicode " << endl;
	else
		cout << "c1 is an unicode " << endl;

	//multicode(ANSI) to widechar(unicode)
    ret = MultiByteToWideChar(CP_UTF8, 0, c, -1, NULL, 0);
	if (ret == 0)
		cout << "error occured" << GetLastError();
	WCHAR *Warray = new WCHAR[ret];
	int req = MultiByteToWideChar(CP_UTF8, 0, c, -1, Warray, ret);
	if (req == 0)
		cout << "c is not converted to widechar " << endl;
	else
		cout << "c is conerted to widechar " << endl;
	cout << "converted to widechar "<<c<<endl<<"buffered is"<<Warray<<endl;
	printf("%S\n", Warray);
	
	//widechar(unicode) to multicode(ANSI)
	ret = WideCharToMultiByte(CP_UTF8, 0, c1, -1, NULL, 0, NULL, NULL);
	CHAR *Aarray = new CHAR[ret];
	req = WideCharToMultiByte(CP_UTF8, 0, c1, -1, Aarray, ret, NULL, NULL);
	if (req == 0)
		cout << "c1 is not converted to multicode " << endl;
	else
		cout << "c1 is conerted to multicode " << endl;
	wcout << "converted to multicode " << c1 << endl;
	cout<< "buffered is" << Aarray << endl;
	//printf("%S\n", Warray);
	system("pause");
}