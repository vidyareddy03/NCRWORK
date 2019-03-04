#include<iostream>
using namespace std;
#define MAX 10
int stack[MAX], top = -1;

void push(char c)
{
	top++;
	stack[top] = c;
}
char pop()
{
	char item;
	if (top == -1)
		return -1;
	item = stack[top];
	top--;
	return item;
}
int priority(char c)
{
	switch (c)
	{
	case '^':return 4;
	case '*':
	case '/':
	case '%':return 3;
	case '-':
	case '+':return 2;
	default:return 1;
	}
}
void main()
{
	char rev[20], prerev[20], infix[20], prefix[20];
	int i, j;
	cout << "enter infix expression ";
	cin >> infix;
	strrev(infix);
	strcpy(rev, infix);
	strcat(rev, "(");
	push(')');

	for (i = 0, j = 0; rev[i] != '\0'; i++)
	{
		if (isalnum(rev[i]))
			prerev[j++] = rev[i];
		else if (rev[i] == ')')
			push(rev[i]);
		else if(rev[i]=='(')
		{
			while (stack[top] != ')')
			{
				prerev[j++] = pop();
			}
			pop();
		}
		else
		{
			while (priority(rev[i]) < priority(stack[top]))
			{
				prerev[j++] = pop();
			}
			push(rev[i]);

		}
	}
	
	//(prefix, prerev);
	prerev[j] = '\0';
	cout << "prefix expression is " << strrev(prerev);
	system("pause");
}