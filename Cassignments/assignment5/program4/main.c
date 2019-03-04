#include<stdio.h>
#include<conio.h>
struct mem
{
	int x : 2;
}s;
void main()
{
	s.x = 5;
	printf("%d", s.x);
	if (s.x == 1)
	{
		printf("little endian\n");
	}
	else if (s.x == 2)
	{
		printf("big endian\n");
	}
	_getch();
}
