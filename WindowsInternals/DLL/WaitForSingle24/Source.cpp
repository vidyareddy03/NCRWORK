#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>

DWORD WINAPI threadFun(LPVOID lparam)
{
	for (int i = 0; i < 3; i++)
	{
		printf("hello %d\n", i);
		Sleep(2000);
	}
	return 0;
}

int main()
{
	DWORD thId1;
	HANDLE hTh1;
	//HANDLE arr_han[2];
	hTh1 = CreateThread(NULL, 0, threadFun, NULL, 0, &thId1);
	if (hTh1 == NULL)
	{
		printf("failed creating thread error %d\n", GetLastError());
		getchar();
		return 1;
	}
	DWORD dw = WaitForSingleObject(hTh1, INFINITE);
	switch (dw)
	{
	case WAIT_OBJECT_0:
		printf("thread is terminated \n");
		break;
	case WAIT_TIMEOUT:
		printf("timeout expired \n");
		break;
	case WAIT_FAILED:
		printf("wait failed \n");
		break;
	}
	CloseHandle(hTh1);
	printf("waiting for user input before exiting the process ");
	getchar();
	return 0;
}