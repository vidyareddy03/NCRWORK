#include<stdio.h>
#include<Windows.h>
#include"dll21.h"
typedef int(*MYPROC)(int, int);
int main()
{
	HMODULE h1;
	int sum, sub, mul, div;
	MYPROC ADD, SUB, MUL, DIV;
	h1 = LoadLibraryEx(
		TEXT("E:\\NCRWork\\WindowsInternals\\DLL\\Debug\\dll22.dll"),
		NULL,
		NULL
		);
	if (h1 == NULL)
	{
		printf("LoadLibraryEx failde due to error %d ", GetLastError());
		getchar();
		return 0;
	}

	// create a thread here

	ADD = (MYPROC)GetProcAddress(h1, (LPCSTR)"add");
	if (ADD == NULL)
	{
		printf("cant call proc address ");
		getchar();
		return 0;
	}
	sum = ADD(30, 50);
	printf("sum of 30 and 50 is %d\n", sum);
	SUB = (MYPROC)GetProcAddress(h1, (LPCSTR)"sub");
	if (SUB == NULL)
	{
		printf("cant call proc address ");
		getchar();
		return 0;
	}
	sub = SUB(30, 50);
	printf("sub of 30 and 50 is %d\n", sub);
	MUL = (MYPROC)GetProcAddress(h1, (LPCSTR)"mul");
	if (MUL == NULL)
	{
		printf("cant call proc address ");
		getchar();
		return 0;
	}
	mul = MUL(30, 50);
	printf("mul of 30 and 50 is %d\n", mul);
	DIV = (MYPROC)GetProcAddress(h1, (LPCSTR)"divv");
	if (DIV== NULL)
	{
		printf("cant call proc address ");
		getchar();
		return 0;
	}
	div = DIV(100, 50);
	printf("div of 100 by 50 is %d\n", div);
	FreeLibrary(h1);
	getchar();
	return 0;
}
/*give the path in c++ -> general -> additional dependencies 
 path of the header folder i.e dll22 folder */