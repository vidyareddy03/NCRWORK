#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node  *rear;
};

class _queueLL_
{
	struct node *start;
public:
	_queueLL_()
	{
		start = NULL;
	}
	~_queueLL_()
	{
		struct node *cur;

		while (start != NULL)
		{
			cur = start;
			start = start->rear;
			delete cur;
		}
	}

	void enque_front(int);
	void enque_last(int);
	int dequeue_front();
	int dequeue_last();
	void display();
};

void _queueLL_::enque_last(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->rear = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		cur = start;
		while (cur->rear != NULL)
			cur = cur->rear;
		cur->rear = temp;
	}

}
void _queueLL_::enque_front(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	if (start == NULL)
		start = temp;
	else
	{
		temp->rear = start;
		start = temp;
	}
	
}

int _queueLL_::dequeue_front()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->rear;
		x = temp->data;
		delete temp;
	}
	else
		cout << "queue is empty";
	return x;
}
int _queueLL_::dequeue_last()
{
	int x = -1;
	if (start != NULL)
	{
		if (start->rear == NULL)//for only one element
		{
			x = start->data;
			delete start;
			start = NULL;

		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->rear->rear != NULL)
				curr = curr->rear;
			x = curr->rear->data;
			delete curr->rear;
			curr->rear = NULL;
		}
	}
	else
		cout << "list is empty" << endl;
	return x; 
	
}

void _queueLL_::display()
{
	if (start != NULL)
	{
		struct node *cur;
		cur = start;
		while (cur != NULL)
		{
			cout << cur->data << "->";
			cur = cur->rear;
		}
	}
	else
		cout << "empty queue" << endl;
}
void main()
{
	_queueLL_ arr;
	int e, choice, p;
	char c;
	do
	{
		cout << "1.enque_first  2.enque_last  3.dequeue_first  4.dequeue_last  5.display ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "enter element to enque ";
			cin >> e;
			arr.enque_front(e);
			break;
		case 2:cout << "enter element to enque ";
			cin >> e;
			arr.enque_last(e);
			break;
		case 3:p = arr.dequeue_front();
			cout << "dequed element is " << p << endl;
			break;
		case 4:	p = arr.dequeue_last();
			cout << "dequed element is " << p << endl;
			break;
		case 5: arr.display();
			break;
		default:cout << "enter the wrong choice"<<endl; break;
		}
		cout << endl << "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");
}