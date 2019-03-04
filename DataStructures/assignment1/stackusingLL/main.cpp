#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class _stackLL_
{
public:
	struct node *start;
	_stackLL_()
	{
		start = NULL;
	}

	~_stackLL_()
	{
		struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}

	
	void push(int);
	int pop();
	int peek();
	void display();
	
};
void _stackLL_::push(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = temp;
	}
}

int _stackLL_::pop()
{
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)//for only one element
		{
			x = start->data;
			delete start;
			start = NULL;

		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "stack is empty" << endl;
	return x;
}

int _stackLL_::peek()
{
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)//for only one element
		{
			x = start->data;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			
		}
	}
	else
		cout << "stack is empty" << endl;
	return x;
}

void _stackLL_::display()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << "->";
		cur = cur->next;
	}
}

void main()
{
	_stackLL_ arr;
	int e, choice, p;
	char c;
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
		cout <<endl<< "do yo want to continue (y/n) ";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");

}