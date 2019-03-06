#include<Windows.h>
#include<iostream>
using namespace std;
int _cdecl main()
{

	LPWSTR *szarglist;
	int nargs;
	int i;
	szarglist = CommandLineToArgvW(GetCommandLine(), &nargs);
	if (NULL == szarglist)
	{
		wcout << L"failed" << endl;
		return 0;
	}
	else
	{
		for (i = 0; i < nargs; i++)
			wcout << szarglist[i] << endl;
	}
	system("pause");
	return 0;
}