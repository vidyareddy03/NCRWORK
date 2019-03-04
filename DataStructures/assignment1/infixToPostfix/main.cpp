#include<iostream>
#include<string.h>
using namespace std;

struct __stack__
{
	int top;
	int size;
	char *s;
};

class _stack_
{
public:
	struct __stack__ sta;
	_stack_()
	{
		sta.top = -1;
		sta.size = 0;
		//strcpy(sta.s, "");
	}
	~_stack_()
	{
		delete sta.s;
	}

	bool isEmpty();
	bool isFull();
	void push(char);
	char pop();
	char peek();
	void getSize(int);


	int priority(char c)
	{
		switch (c)
		{
		
		case '^':return 5;
		case '*': 
		case '/': return 4;
		case '+':
		case '-':return 3;
		case '(':
		case '{':
		case '[':
			return 2;
		}
		return 0;
	}
	void postfix(char *str)
	{
		char pos[20];
		//strcat(str, ")");
		int i, j = 0;
		//push('(');
		for (i = 0; str[i] != '\0'; i++)
		{
			
			 if (isalpha(str[i]))
			{
				pos[j++] = str[i];
			}
			else if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
			{
				push(str[i]);
			}
			
			
			else if (str[i] == ')') //|| (str[i] == '}') || (str[i] == ']'))
			{
				while (peek() != '(')//|| peek() != '{' || peek() != '[')
					pos[j++] = pop();
				pop();
			}
			else if (str[i] == '}') //|| (str[i] == '}') || (str[i] == ']'))
			{
				while (peek() != '{')//|| peek() != '{' || peek() != '[')
					pos[j++] = pop();
				pop();
			}
			else if (str[i] == ']') //|| (str[i] == '}') || (str[i] == ']'))
			{
				while (peek() != '[')//|| peek() != '{' || peek() != '[')
					pos[j++] = pop();

				pop();
			}
			else
			{
				while (priority(str[i]) <= priority(peek()))
					pos[j++] = pop();
				push(str[i]);
			}
			}

		while (!isEmpty())
			pos[j++] = pop();
		
		pos[j] = '\0';
		cout << "postfix expression is " << pos << endl;
	}
	
};

	void _stack_::getSize(int n)
	{
		sta.size = n;
		sta.s = new char[n];
	}
	bool _stack_::isEmpty()
	{
		return (sta.top == -1);
	}
	bool _stack_::isFull()
	{
		return(sta.top == (sta.size - 1));
	}
	void _stack_::push(char ele)
	{
		if (!isFull())
		{
			sta.s[++sta.top] = ele;
		}
		//else
			//cout << "stack over flow";
	}
	char _stack_::pop()
	{
		char x = '\0';
		if (!isEmpty())
		{
			x = sta.s[sta.top--];
		}
		//else
			//cout << "stack under flow";
		return x;
	}
	char _stack_::peek()
	{
		char x = '\0';;
		if (!isEmpty())
		{
			x = sta.s[sta.top];
		}
		//else
		//	cout << "stack under flow";
		return x;
	}



void main()
{
	_stack_ arr;
	int size;
	char str[15];
	cout << "enter the size of stack ";
	cin >> size;
	arr.getSize(size);
	cout << "enter the infix expression ";
	cin >> str;
	arr.postfix(str);
	
	system("pause");

}