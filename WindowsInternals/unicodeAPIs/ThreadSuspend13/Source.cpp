#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<stdlib.h>

DWORD WINAPI thread_func(LPVOID iparam)
{
	for (int i = 0; i < 1000; i++)
	{
		printf("i=(%d)\n", i);
		//Sleep(5000);
	}
	return 0;
}

int main()
{
	DWORD thID1;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &thID1);
	if (hThread == NULL)
	{
		printf("unable to create the thread");
		getchar();
		return 1;
	}
	else
	{
		Sleep(5000);
		ResumeThread(hThread);
	}
	
	/*WaitForSingleObject(hThread, 1000);
	printf("waiting for user input before exiting the process\n");*/
	getchar();
	CloseHandle(hThread);
	return 0;
}