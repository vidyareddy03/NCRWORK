#include<stdio.h>
#include<iostream>
#define MAX 100
#define Employee(name,company) #name " works in " #company " company"
#define Print(s) printf("token"#s" = %d ",token##3);
int main()
{
	int token3 = 100;
	printf("%s\n", Employee(vidya, NCR));
	Print(3);
#ifdef MAX
#undef MAX
#define MAX 99;
#else
	printf("%d", MAX);
#endif
	system("pause");
	return 0;
}