#include<stdio.h>
#include<ctype.h>
int main()
{
	FILE *fp;
	char s[20], c[50], ch;
	int i;
	printf("enter file name\n");
	scanf("%[^\n]s", s);
	printf("enter line of characters\n");
	scanf(" %[^\n]s", c);
	fp = fopen(s, "w");
	for (i = 0; c[i] != '\0'; i++)
	{
		if (islower(c[i]))
			putc(toupper(c[i]), fp);
		else
			putc(tolower(c[i]), fp);

	}
	fclose(fp);
	fp = fopen(s, "r");
	while (!feof(fp))
	{
		ch = getc(fp);
		printf("%c", ch);
		if (ch == 'A' || ch == 'E' )//|| ch == 'I' || ch == 'O' || ch == 'U')
		{
			printf("\ncurrent position = %d\n", ftell(fp));
			fseek(fp, 5, SEEK_CUR);
		}
	}
	return 0;
}