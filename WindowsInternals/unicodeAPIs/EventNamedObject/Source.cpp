#include<Windows.h>
#include<stdio.h>
#include<conio.h>
#include<tchar.h>
using namespace std;
int _tmain()
{
	HANDLE g_Event = CreateEvent(NULL, FALSE, FALSE, TEXT("namedobject"));
	if (g_Event == NULL)
	{
		_tprintf(L"object not created");
	}
	else
		_tprintf(L"object created");
	getchar(); 
	CloseHandle(g_Event);
	
	return 0;
}