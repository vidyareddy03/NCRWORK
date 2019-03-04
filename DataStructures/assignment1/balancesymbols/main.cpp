#include<iostream>
#include<string>
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
		strcpy(sta.s,"");
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
	//void display();
	void getSize(int);
	void balancing(char *s);
};

void _stack_::getSize(int n)
{
	sta.size = n;
	sta.s = new char[n];
	for (int i = 0; i < n; i++)
		sta.s[i] = 0;
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
	else
		cout << "stack over flow";
}
char _stack_::pop()
{
	char x = '\0';
	if (!isEmpty())
	{
		x = sta.s[sta.top--];
	}
	else
		cout << "stack under flow";
	return x;
}
char _stack_::peek()
{
	char x = '\0';;
	if (!isEmpty())
	{
		x = sta.s[sta.top];
	}
	else
		cout << "stack under flow";
	return x;
}
/*void _stack_::display()
{
	int i;
	for (i = 0; i < sta.size; i++)
		cout << sta.s[i] << endl;
}
*/
void _stack_::balancing(char *s)
{
	int i,flag=0;
	char ch,r;
	for (i = 0; s[i] != '\0'; i++)
	{
		ch = s[i];
		switch (ch)
		{
		case '(':
		case '{':
		case '[':
			push(ch); break;
		case ')':
		case '}':
		case ']':
			if (!isEmpty())
			{
				if ((ch == ')' && peek() == '(') || (ch == '}' && peek() == '{') || (ch == ']' && peek() == '['))
				{
					r = pop();
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
				flag = 1;
			
		}
		if (flag == 1 )
		{
			break;
		}
		
	}
	if (!isEmpty() || flag==1)
	{
		cout << "not balanced" << endl;
	}
	else
		cout << "balanced" << endl;
}

void main()
{
	_stack_ arr;
	int e, n, choice, p;
	char c;
	char str[10];
	cout << "enter the size of stack";
	cin >> n;
	arr.getSize(n);
	cout << "enter the string ";
	cin >> str;
	arr.balancing(str);
	system("pause");

}