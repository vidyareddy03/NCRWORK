#include<Windows.h>
#include<stdio.h>
hdll = LoadLibraryEx(TEXT("E:\NCRWork\WindowsInternals\DLL\Debug"), NULL, DONT_RESOLVE_DLL_REFERENCES);
if (hdll == NULL)
{
	printf("load library failed due to error %d \n", GetLastError());
}