#include<iostream>
using namespace std;
struct __queue__
{
	int front;
	int rear;
	int size;
	int *s;
};

class _queue_
{
	struct __queue__ qu;
public:
	_queue_()
	{
		qu.front = qu.rear = -1;
		qu.size = 0;
	}
	~_queue_()
	{
		delete qu.s;
	}

	void getSize(int);
	void enque(int);
	int dequeue();
	bool underflow();
	bool overflow();
	void display();
};
void _queue_::getSize(int n)
{
	qu.size = n;
	qu.s = new int[n];
	for (int i = 0; i < n; i++)
		qu.s[i] = 0;
}
bool _queue_::underflow()
{
	return (qu.front == -1 && qu.rear == -1);
}
bool _queue_::overflow()
{
	return (qu.rear == qu.size - 1);
}
void _queue_::enque(int ele)
{
	if (!overflow())
	{
		if (qu.rear == qu.front && qu.front == -1)
			qu.front++;
		qu.s[++qu.rear] = ele;
	}
	else
		cout << "queue overflow" << endl;
}
int _queue_::dequeue()
{
	int x = -1;
	if (!underflow())
	{
		if (qu.front == qu.rear)
		{
			x = qu.s[qu.front];
			qu.front = qu.rear = -1;

		}
		else
			x = qu.s[qu.front++];
	}
	else
		cout << "queue is empty" << endl;
	return x;
}
void _queue_::display()
{
	if (qu.front == qu.rear && qu.front == -1)
	{
		cout << "empty queue" << endl;
	}
	else
	{
		int i;
		for (i = qu.front; i <= qu.rear; i++)
			cout << qu.s[i] << endl;
	}
}

void main()
{
	_queue_ arr;
	int e, n, choice, p;
	char c;
	cout << "enter the size of queue";
	cin >> n;
	arr.getSize(n);
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
		cout << "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");
}