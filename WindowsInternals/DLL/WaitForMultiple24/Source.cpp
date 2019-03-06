#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>

DWORD WINAPI threadFun1(LPVOID lparam)
{
	//for (int i = 0; i < 3; i++)
	{
		printf("Thread1 \n" );
		Sleep(4000);
	}
	return 0;
}

DWORD WINAPI threadFun2(LPVOID lparam)
{
	// (int i = 0; i < 3; i++)
	{
		printf("Thread2 \n" );
		Sleep(3000);
	}
	return 0;
}

int main()
{
	DWORD thId1,thId2;
	HANDLE hTh1,hTh2;
	HANDLE arr_han[2];
	hTh1 = CreateThread(NULL, 0, threadFun1, NULL, 0, &thId1);
	if (hTh1 == NULL)
	{
		printf("failed creating thread error %d\n", GetLastError());
		getchar();
		return 1;
	}
	hTh2 = CreateThread(NULL, 0, threadFun2, NULL, 0, &thId2);
	if (hTh2 == NULL)
	{
		printf("failed creating thread error %d\n", GetLastError());
		getchar();
		return 1;
	}
	arr_han[0] = hTh1;
	arr_han[1] = hTh2;
	//DWORD dw = WaitForMultipleObjects(2, arr_han, TRUE, INFINITE);
	//DWORD dw = WaitForMultipleObjects(2, arr_han, FALSE, INFINITE);
	DWORD dw = WaitForMultipleObjects(2, arr_han, FALSE, 8000);
	switch (dw)
	{
	case WAIT_OBJECT_0+0:
		printf("thread1 is terminated \n");
		break;
	case WAIT_OBJECT_0 + 1:
		printf("thread2 is terminated \n");
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