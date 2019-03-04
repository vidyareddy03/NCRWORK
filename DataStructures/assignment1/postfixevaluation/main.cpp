#include<iostream>
using namespace std;
#define MAX 10
int stack[MAX], top = -1;

void push(int item)
{
	top++;
	stack[top] = item;
}

int pop()
{
	int item;
	if (top == -1)
		return -1;
	item = stack[top];
	top--;
	return item;
}

void main()
{
	char postfix[20];
	int i,t,op1,op2,res;
	cout << "enter postfix expression ";
	cin >> postfix;
	strcat(postfix, ")");
	for (i = 0; postfix[i] != '\0'; i++)
	{
		if(isdigit(postfix[i]))
		{
			t = postfix[i] - '0';
			push(t);
		}
		else
		{
			op2 = pop();
			op1 = pop();
			switch (postfix[i])
			{
			case '^':res = pow(op1, op2); break;
			case '%':res = op1%op2; break;
			case '/':res = op1 / op2; break;
			case '*':res = op1*op2; break;
			case '+':res = op1 + op2; break;
			case '-':res = op1 - op2; break;
			}
			push(res);
		}
	}
	cout << "eval expression is " << pop();
	system("pause");
	
}