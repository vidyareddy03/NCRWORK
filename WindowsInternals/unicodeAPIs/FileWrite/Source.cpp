/* open existing file and write the contents in it */
#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
using namespace std;
#define BUFSIZE 20
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	//LPCWSTR name;
	//name = L"sample.txt";
	TCHAR buffer[BUFSIZE]=L"hello good";
	if (argc != 2)
	{
		_tprintf(_T("usage fileopen.exe "));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("FILE doesnot Created. error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("FILE is created\n"));
	//ZeroMemory(buffer, BUFSIZE);
	DWORD nbr, dwNbw;
	BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &dwNbw, NULL);
	if (ret == 0)
	{
		_tprintf(_T("can't write, error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	_tprintf(_T("text into (%s) %S \n"), argv[1], buffer);
	getchar();
	return TRUE;
}