#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
long g_X = 0;
DWORD WINAPI thread_func(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_X, 1);
	//g_X++;
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_X, 1);
	//g_X++;
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE arr_hand[2];
	while (1)
	{
		g_X = 0;
		hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &thID1);
		if (hThread1 == NULL)
		{
			printf("unable to create the thread\n");
			getchar();
			return 1;
		}
		hThread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &thID2);
		if (hThread2 == NULL)
		{
			printf("unable to create the thread");
			getchar();
			return 1;
		}
		arr_hand[0] = hThread1;
		arr_hand[1] = hThread2;
		WaitForMultipleObjects(2, arr_hand, TRUE, INFINITE );
		
		printf("g_x is %d\n", g_X);
		if (g_X == 1)
			break;
	}
	printf("waiting for user input before exiting the process\n");
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	getchar();
	return 0;
}