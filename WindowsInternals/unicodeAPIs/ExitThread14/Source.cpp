#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include<stdlib.h>
DWORD exitcode=1;
DWORD WINAPI thread_func(LPVOID iparam)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		if (i == 5)
		{
			
			printf("thread exited \n");
			ExitThread(exitcode);
		}
		//Sleep(1000);
	}
	return 0;
}

int main()
{
	DWORD thID1;
	HANDLE hThread;
	//LPDWORD exitcode;
	hThread = CreateThread(NULL, 0, thread_func, NULL, 0, &thID1);
	if (hThread == NULL)
	{
		printf("unable to create the thread");
		getchar();
		return 1;
	}
	WaitForSingleObject(hThread, 1000);

	BOOL ret = GetExitCodeThread(hThread, &exitcode);
	printf("exitcode %d ", exitcode);
	if (ret == 0)
	{
		//ExitThread(exitcode);
		printf("thread closed unsuccessfully \n");

	}
	else
		printf("closed successfully\n");
	
	
	//printf("waiting for user input before exiting the process\n");
	getchar();
	CloseHandle(hThread);
	return 0;
}