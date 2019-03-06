#include<stdio.h>
#include<Windows.h>
#include"dll21.h"
BOOL WINAPI DllMain(HANDLE hand, DWORD msg, LPVOID res)
{
	switch (msg)
	{
	case DLL_PROCESS_ATTACH:
		printf("DLL process attached \n");
		break;
	case DLL_PROCESS_DETACH:
		printf("DLL process detached \n");
		break;
	/*case DLL_THREAD_ATTACH:
		printf("DLL thread attached \n");
		break;
	case DLL_THREAD_DETACH:
		printf("DLL process attached \n");
		break;*/
	}
	return TRUE;
}