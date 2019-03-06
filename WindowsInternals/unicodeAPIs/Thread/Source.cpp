#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<stdlib.h>

DWORD WINAPI thread_func(LPVOID iparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		Sleep(1000);
	}
	return 0;
}

int main()
{
	DWORD thID1;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func, NULL, 0, &thID1);
	if (hThread == NULL)
	{
		printf("unable to create the thread");
		getchar();
		return 1;
	}
	CloseHandle(hThread);
	printf("waiting for user input before exiting the process\n");
	getchar();
	return 0;
}