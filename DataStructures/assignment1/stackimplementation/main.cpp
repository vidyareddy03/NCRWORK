#include<iostream>
using namespace std;
struct __stack__
{
	int top;
	int size;
    int *s;
};

class _stack_
{
public:
	struct __stack__ sta;
	_stack_()
	{
		sta.top = -1;
		sta.size = 0;
		sta.s = NULL;
	}
	~_stack_()
	{
		delete sta.s;
	}
	
	bool isEmpty();
	bool isFull();
	void push(int);
	int pop();
	int peek();
	void display();
	void getSize(int);
};

void _stack_::getSize(int n)
{
	sta.size = n;
	sta.s = new int[n];
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
void _stack_::push(int ele)
{
	if (!isFull())
	{
		sta.s[++sta.top] = ele;
	}
	else
		cout << "stack over flow";
}
int _stack_::pop()
{
	int x = -999;
	if (!isEmpty())
	{
		x = sta.s[sta.top--];
	}
	else
		cout << "stack under flow";
	return x;
}
int _stack_::peek()
{
	int x = -999;
	if (!isEmpty())
	{
		x = sta.s[sta.top];
	}
	else
		cout << "stack under flow";
	return x;
}
void _stack_::display()
{
	int i;
	for (i = 0; i < sta.size; i++)
		cout << sta.s[i]<<endl;
}

void main()
{
	_stack_ arr;
	int e,n,choice,p;
	char c;
	cout << "enter the size of stack";
	cin >> n;
	arr.getSize(n);
	do
	{
		cout << "1.push 2.pop 3. peek 4.display ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "enter element to push ";
			cin >> e;
			arr.push(e);
			break;
		case 2:p = arr.pop();
			cout << "popped element is " << p << endl;
			break;
		case 3: p = arr.peek();
			cout << "top element is " << p << endl;
			break;
		case 4: arr.display();
			break;
		default:cout << "enter the wrong choice"; break;
		}
		cout << "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');

	

	system("pause");

}