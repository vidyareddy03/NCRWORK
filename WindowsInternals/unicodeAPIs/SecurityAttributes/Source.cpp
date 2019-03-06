#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(int argc, TCHAR *argv[])
{
	_SECURITY_ATTRIBUTES s;
	ZeroMemory(&s, sizeof(s));
	s.nLength = sizeof(s);
	s.bInheritHandle = NULL;
	s.bInheritHandle = TRUE;
	HANDLE g_Event = CreateEvent(&s, FALSE, FALSE, TEXT("eventobject"));
	if (g_Event == NULL)
	{
		_tprintf(L"object not created");
	}
	else
		_tprintf(L"object created");
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
		TRUE,          // Set handle inheritance to TRUE
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

	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);
	getchar();

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(g_Event);

}