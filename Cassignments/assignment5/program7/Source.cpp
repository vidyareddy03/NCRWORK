#include<stdio.h>
int main(int argc, char *argv[])
{
	int i; char c;
	/*for (i = 1; i < argc; i++)
	printf("%s\n", argv[i]);*/
	FILE *fp;
	FILE *fp1;
	fp = fopen(argv[1], "w");
	if (fp == NULL)
	{
		printf("file is not created\n");
		return -1;
	}
	//scanf("%c", &c);
	while ((c = getchar()) != EOF)
	{
		putc(~c, fp);
		//scanf("%c", &c);
	}
	fclose(fp);
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL)
	{
		printf("Cannot open file\n");
		return -1;
	}
	printf("Contents of file are:\n");
	while (!feof(fp1))
	{
		c = getc(fp1);
		printf("%c", ~c);
	}
	rewind(fp);
	printf("\n");
	printf("Contents of file in one's compliment are:\n");
	while (!feof(fp1))
	{
		c = getc(fp1);
		printf("%c", c);
	}
	fclose(fp1);
	return 0;
}