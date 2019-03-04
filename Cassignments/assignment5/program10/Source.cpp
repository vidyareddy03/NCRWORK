#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct india
{
	char state[30];
	char capital[30];
};
int main()
{
	FILE *fp;
	int n;
	char ch;
	struct india ind[3], ret[3];
	int i, c;
	char f[20], coun[30];
	printf("enter file name\n");
	scanf("%[^\n]s", f);
	//printf("%s\n", f);
	fp = fopen(f, "w");
	if (fp == NULL)
	{
		printf("File cannot be created\n");
		return -1;
	}
	cout << "enter number of states to be entered ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		printf("enter state and capital\n");
		scanf(" %[^\n]s", &ind[i].state);
		scanf(" %[^\n]s", &ind[i].capital);
		//printf("%s\n", ind[i].state);
	}
	fwrite(ind, sizeof(struct india), 3, fp);
	fclose(fp);
	fp = fopen(f, "r");
	fread(ret, sizeof(struct india), 3, fp);
	/*for (i = 0; i < 3; i++)
	{
	printf("%s %s\n", ret[i].state, ret[i].capital);
	}*/
	do {
		printf("enter 1.to know capital 2.determine state if capital is given 3.terminate\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:printf("enter state\n");
			scanf(" %[^\n]s", coun);
			for (i = 0; i < 3; i++)
			{
				//printf("%s", ret[i].state);
				if (strcmp(coun, ret[i].state) == 0)
				{
					printf("%s\n", ret[i].capital);
					break;
				}
			}
			break;
		case 2:printf("enter capital\n");
			scanf(" %[^\n]s", coun);
			for (i = 0; i < 3; i++)
			{
				//printf("%s", ret[i].state);
				if (strcmp(coun, ret[i].capital) == 0)
				{
					printf("%s\n", ret[i].state);
					break;
				}
			}
			break;
			cout << "do you want to continue(y/n) ";
			cin >> ch;
		}
	} while (ch == 'y' || ch == 'Y');
	system("pause");
	return 0;
}