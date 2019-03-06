#include<Windows.h>
#include<iostream>
#include<tchar.h>//for _tprintf
using namespace std;
void DumpEnvString(PTSTR pEnvBlock[])
{
	int curr = 0;
	PTSTR *pElement = (PTSTR*)pEnvBlock;
	PTSTR pcurrent = NULL;
	while (pElement != NULL)
	{
		pcurrent = (PTSTR)(*pElement);
		if (pcurrent == NULL)
			pElement = NULL;
		else
		{
			_tprintf(TEXT("[%u]%s\n\n"), curr, pcurrent);
			curr++;
			pElement++;

		}
	}
}
int _tmain(int argc,TCHAR *argv[],TCHAR *env[])
{
	DumpEnvString(env);
	TCHAR envVarString[] = TEXT("%classpath%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	if (!ret)
	{
		cout << GetLastError() << endl;
		getchar();
		return 0;
	}
	else
		wcout << buffer << endl;
	getchar();
}

