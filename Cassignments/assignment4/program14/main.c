#include<stdio.h> 
int main(void)
{
	char a[100];
	int i, j;
	printf("Enter a word: ");
	gets(a);

	for (i = 0; a[i] != '\0'; i++)
	{
		for (j = i; a[j] != '\0'; j++)
			printf("%c", a[j]);

		for (j = 0; j<i; j++)
			printf("%c", a[j]);
		printf("\n");
	}
	system("pause");
	return 0;
}