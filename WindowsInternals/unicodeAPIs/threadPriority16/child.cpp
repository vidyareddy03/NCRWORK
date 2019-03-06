#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include<strsafe.h>
#include<iostream>
using namespace std;
#define BUFFSIZE 100

DWORD WINAPI Thread_fun(LPVOID lparam)
{
	printf("In thread Function \n ");
	return 0;
}
int main(int argc, CHAR* argv[])
{
	cout << GetPriorityClass(GetCurrentProcess()) << endl;
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
	cout << GetPriorityClass(GetCurrentProcess()) << endl;

	DWORD thId;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, Thread_fun, NULL, CREATE_SUSPENDED, &thId);
	if (hThread == NULL)
	{
		printf("unable to create a thread. ERROR %d \n", GetLastError());
		getchar();
		return 0;
	}
	BOOL ret = SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	if (ret != 0)
	{
		printf("successfull. the priority of the thread is %ld\n", GetThreadPriority(hThread));
	}
	else
	{
		printf("set priority of thread is failed. ERROR %d\n", GetLastError());
		return 0;
	}
	ResumeThread(hThread);
	printf(" thread creation successful \n");
	getchar();
	CloseHandle(hThread);
	return 0;
}