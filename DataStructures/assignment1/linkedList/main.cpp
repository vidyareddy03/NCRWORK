#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class __list__
{
	struct node *start;
public:
	__list__()
	{
		start = NULL;
	}
	~__list__()
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
	void reverse();
	friend void P(struct node *);
};

void __list__::Insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}

void __list__::Insert_Last(int ele)
{
	struct node *temp,*cur;
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
void __list__::Insert_After(int sele,int ele)
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
			cur->next = temp;
		}
		else
			cout << "element not found";
	}
	else
		cout << "list is empty";
}
void __list__::Insert_Before(int sele, int ele)
{
	if (start != NULL)
	{
		if (start->data == sele)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{
			struct node *cur;
			cur = start;
			while (cur->next != NULL &&cur->next->data != sele)
			{
				cur = cur->next;
			}
			if (cur->next != NULL)//ele found
			{
				struct node *temp;
				temp = new node;
				temp->data = ele;
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty";
}

int __list__::Delete_first()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty";
	return x;
}

int __list__::Delete_last()
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
		cout << "list is empty" << endl;
	return x;
}
void __list__::Delete_spec(int ele)
{
	if (start != NULL)
	{
		struct node *temp, *cur;
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			cur = start;
			while (cur->next != NULL && cur->next->data != ele)
				cur = cur->next;
			if (cur->next != NULL)//ele found
			{
				temp = cur->next;
				cur->next = temp->next;
				delete temp;

			}
			else
				cout << "element not found" << endl;
		}

	}
	else
		cout << "list is empty" << endl;
}

void __list__::Travel_forward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->data<<"->";
		cur = cur->next;
	}
}

void __list__::Travel_backward()
{
	if (start != NULL)
	{
		P(start);
	}
}
void P(struct node *curr)
{
	if (curr != NULL)
	{
		P(curr->next);
		cout << curr->data<<"->";
	}
}

void __list__::reverse()
{
	struct node *rev,*temp;
	rev = NULL;
	if (start != NULL)
	{
		if (start->next != NULL)
		{
			while (start != NULL)
			{
				temp = start;
				start = temp->next;
				temp->next = rev;
				rev = temp;
			}
			start = rev;
		}
	}
}

void main()
{
	__list__ arr;
	int e, n, choice, p,loc;
	char c;
	do
	{
		cout << "1.inseert_begining 2.insert_last 3. insert_after 4.insert_before 5.delete_first "<<endl<<"6.delete_last 7.delete_specific 8.forward_travel 9.travel_backward 10.reverse ";
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
			arr.Insert_After(loc,e);
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
			cout << "item deleted "  << endl;
			break;
		case 8:
			arr.Travel_forward(); break;
		case 9:
			arr.Travel_backward(); break;
		case 10:
			arr.reverse(); break;
		default:cout << "enter the wrong choice"; break;
		}
		cout << "do yo want to continue (y/n)";
		cin >> c;


	} while (c == 'y' || c == 'Y');



	system("pause");

}