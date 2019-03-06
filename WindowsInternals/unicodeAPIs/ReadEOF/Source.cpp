/* open existing file using EOF  */
#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define BUFSIZE 50
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	//LPCWSTR name;
	//name = L"sample.txt";
	TCHAR buffer[BUFSIZE];
	if (argc != 2)
	{
		_tprintf(_T("usage fileopen.exe "));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("FILE doesn't exist in the path. error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("FILE is opened\n"));
	ZeroMemory(buffer, sizeof(buffer));
	//memcpy(buffer, '\0', BUFSIZE);
	DWORD nbr;
	while (1)
	{
		
		BOOL ret = ReadFile(hFile, &buffer, BUFSIZE, &nbr, NULL);
		if (ret == FALSE)
		{
			_tprintf(_T("can't read, error[%d]"), GetLastError());
			getchar();
			return FALSE;
		}
		else if (ret == TRUE && nbr == 0)//EOF
		{
			_tprintf(L"\nEOF reached");
			break;
		}
		_tprintf(_T("text from (%s) %LS \n"), argv[1], buffer);

		/*for (int i = 0; i < _tcslen(buffer); i++)
			_tprintf(_TEXT("%C"), buffer[i]);*/
	}
	CloseHandle(hFile);
	_tprintf(_T("\ntext from (%s) is %S \n"), argv[1], buffer);
	getchar();
	return TRUE;
}