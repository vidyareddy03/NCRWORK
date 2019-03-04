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
		
		while(start != NULL)
		{
			cur = start;
			start = start->rear;
			delete cur;
		}
	}

	void enque(int);
	int dequeue();
	void display();
};

void _queueLL_::enque(int ele)
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

int _queueLL_::dequeue()
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
	int e,  choice, p;
	char c;
	do
	{
		cout << "1.enque 2.dequeue 3.display ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "enter element to enque ";
			cin >> e;
			arr.enque(e);
			break;
		case 2:p = arr.dequeue();
			cout << "dequed element is " << p << endl;
			break;

		case 3: arr.display();
			break;
		default:cout << "enter the wrong choice"; break;
		}
		cout <<endl<< "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");
}