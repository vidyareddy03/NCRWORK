#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *fp;
	char ch;
	fp = fopen("sample.txt", "r");
	while (!feof(fp))
	{
		ch = fgetc(fp);
		printf("%c", ch);

	}
	getchar();
}