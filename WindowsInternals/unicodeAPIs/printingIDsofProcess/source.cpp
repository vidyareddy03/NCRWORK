#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (argc != 2)
	{
		printf("Usage: %s [cmdline] error [%d]\n", argv[0], GetLastError());
		getchar();
		return;
	}

	// Start the child process. 
	if (!CreateProcess(NULL,   // No module name (use command line)
		argv[1],        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		getchar();
		return;
	}
	printf("current process ID is %d\n", GetCurrentProcessId());
	printf("current Thread ID is %d\n", GetCurrentThreadId());
	printf(" process ID is %d\n", GetProcessId(pi.hProcess));
	printf("thread ID is %d\n", GetThreadId(pi.hThread));
	printf("process ID of thread is %d\n", GetProcessIdOfThread(pi.hThread));
	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);
	getchar();

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

}