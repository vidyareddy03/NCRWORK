#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
};
class __DLlist__
{
	struct node *start;
public:
	__DLlist__()
	{
		start = NULL;
	}
	~__DLlist__()
	{
		struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
	void Insert_first(int);
	void Insert_Last(int);
	void Insert_After(int, int);
	void Insert_Before(int, int);
	int Delete_first();
	int Delete_last();
	void Delete_spec(int);
	void Travel_forward();
	void Travel_backward();
	//void reverse();
	//friend void P(struct node *);
};

void __DLlist__::Insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if (start != NULL)
		start->prev = temp;
	start = temp;
}

void __DLlist__::Insert_Last(int ele)
{
	struct node *temp, *cur;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		temp->prev = cur;
		cur->next = temp;
	}

}
void __DLlist__::Insert_After(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *cur;
		cur = start;
		while (cur != NULL &&cur->data != sele)
		{
			cur = cur->next;
		}
		if (cur != NULL)//ele found
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = cur->next;
			temp->prev = cur;
			if (cur->next != NULL)
				cur->next->prev = temp;
			cur->next = temp;

		}
		else
			cout << "element not found";
	}
	else
		cout << "list is empty";
}
void __DLlist__::Insert_Before(int sele, int ele)
{
	if (start != NULL)
	{
		    struct node *cur,*temp;
			cur = start;
			while (cur != NULL &&cur->data != sele)
			{
				cur = cur->next;
			}
			if (cur != NULL)//ele found
			{
				
				temp = new node;
				temp->data = ele;
				temp->prev = cur->prev;
				temp->next = cur;
				if (cur->prev != NULL)
					cur->prev->next = temp;
				else
					start = temp;
				cur->prev = temp;
			}
			else
				cout << "element not found";
	}
	else
		cout << "list is empty";
}

int __DLlist__::Delete_first()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty";
	return x;
}

int __DLlist__::Delete_last()
{
	int x = -1;
	if (start != NULL)
	{
			struct node *curr;
			curr = start;
			while (curr->next != NULL)
				curr = curr->next;
			x = curr->data;
			if (curr->prev != NULL)
				curr->prev->next = NULL;
			else
				start = NULL;
			delete curr;		
	}
	else
		cout << "list is empty" << endl;
	return x;
}
void __DLlist__::Delete_spec(int ele)
{
	if (start != NULL)
	{
		struct node  *cur;
		cur = start;
			while (cur != NULL && cur->data != ele)
				cur = cur->next;
			if (cur != NULL)//ele found
			{
				if (cur->prev != NULL)
					cur->prev->next = cur->next;
				else
					start = cur->next;
				if (cur->next != NULL)
					cur->next->prev = cur->prev;
				
				delete cur;

			}
			else
				cout << "element not found" << endl;
		

	}
	else
		cout << "list is empty" << endl;
}

void __DLlist__::Travel_forward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data << "->";
		cur = cur->next;
	}
}

void __DLlist__::Travel_backward()
{
	if (start != NULL)
	{
		struct node *cur;
		cur = start;
		while (cur->next != NULL)
			cur = cur->next;
		while (cur != NULL)
		{
			cout << cur->data << "->";
			cur = cur->next;
		}
	}
}


void main()
{
	__DLlist__ arr;
	int e, n, choice, p, loc;
	char c;
	do
	{
		cout << "1.inseert_begining 2.insert_last 3. insert_after 4.insert_before 5.delete_first " << endl << "6.delete_last 7.delete_specific 8.forward_travel 9.travel_backward  ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "enter element to insert ";
			cin >> e;
			arr.Insert_first(e);
			break;
		case 2:
			cout << "enter element to insert ";
			cin >> e;
			arr.Insert_Last(e);
			break;
		case 3:
			cout << "enter element to insert ";
			cin >> e;
			cout << "enter item after which it need to be inserted ";
			cin >> loc;
			arr.Insert_After(loc, e);
			break;
		case 4:
			cout << "enter element to insert ";
			cin >> e;
			cout << "enter item before which it need to be inserted ";
			cin >> loc;
			arr.Insert_Before(loc, e);
			break;
		case 5:p = arr.Delete_first();
			cout << "deleted first element is " << p << endl;
			break;
		case 6:p = arr.Delete_last();
			cout << "deleted last  element is " << p << endl;
			break;
		case 7:cout << "enter item to be deleted ";
			cin >> loc;
			arr.Delete_spec(loc);
			cout << "item deleted " << endl;
			break;
		case 8:
			arr.Travel_forward(); break;
		case 9:
			arr.Travel_backward(); break;
		//case 10:
			//arr.reverse(); break;
		default:cout << "enter the wrong choice"; break;
		}
		cout << "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");

}