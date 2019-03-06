#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
HANDLE hEvent;
DWORD WINAPI COUNT_WORDS(LPVOID lparam)
{
	WaitForSingleObject(hEvent, INFINITE);
	printf("Counting words\n");
	return 0;
}
DWORD WINAPI CHECK_SPELLING(LPVOID lparam)
{
	WaitForSingleObject(hEvent, INFINITE);
	printf("check spelling \n");
	return 0;
}
DWORD WINAPI CHECK_GRAMMAR(LPVOID lparam)
{
	WaitForSingleObject(hEvent, INFINITE);
	printf("checking grammar\n");
	return 0;
}

int main()
{
	DWORD thId1, thId2, thId3;
	HANDLE hTh1, hTh2, hTh3;
	hEvent = CreateEvent(NULL, TRUE,FALSE, TEXT("eventobject"));
	hTh1 = CreateThread(NULL, 0, COUNT_WORDS, NULL, 0, &thId1);
	if (hTh1 == NULL)
	{
		cout << "thread failed to create error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	hTh2 = CreateThread(NULL, 0, CHECK_SPELLING, NULL, 0, &thId2);
	if (hTh2 == NULL)
	{
		cout << "thread failed to create error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	hTh3 = CreateThread(NULL, 0, CHECK_GRAMMAR, NULL, 0, &thId3);
	if (hTh3 == NULL)
	{
		cout << "thread failed to create error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	cout << "main program\n";
	SetEvent(hEvent);
	cout << "waitng for user input\n";
	getchar();
	return 0;
}