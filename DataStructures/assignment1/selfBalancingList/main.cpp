#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class __selfList__
{
	struct node *start;
public:
	__selfList__()
	{
		start = NULL;
	}
	~__selfList__()
	{
		struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
	void Insert_Last(int);
	void balance(int);
	void Travel_forward();
};

void __selfList__::Insert_Last(int ele)
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

void __selfList__::balance(int ele)
{
	if (start != NULL)
	{
		struct node *cur,*link;
		cur = start;
		link = NULL;
		while (cur != NULL && cur->data != ele)
		{
			link = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			link->next = cur->next;
			cur->next = start;
			start = cur;

		}
	}
}
void __selfList__::Travel_forward()
{
	if (start != NULL)
	{
		struct node *cur;
		cur = start;
		while (cur != NULL)
		{
			cout << cur->data << "->";
			cur = cur->next;
		}
	}
	cout << "empty list " << endl;
}

void main()
{
	__selfList__ arr;
	int e, choice;
	char c;
	do
	{
		cout << "1.inseert_last   2.self balance 3. forward_travel "  ;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "enter element to insert ";
			cin >> e;
			arr.Insert_Last(e);
			break;
		case 2:
			cout << "enter element to balance ";
			cin >> e;
			arr.balance(e);
			break;
		case 3:
			arr.Travel_forward(); break;
		default:cout << "enter the wrong choice"<<endl; break;
		}
		cout << "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");

}

