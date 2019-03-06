/* open existing file and read the contents in it */
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
	ZeroMemory(buffer, BUFSIZE);
	DWORD nbr, dwNbw;
	BOOL ret = ReadFile(hFile, buffer, BUFSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("can't read, error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	_tprintf(_T("text from (%s) %S \n"), argv[1], buffer);
	getchar();
	return TRUE;
}