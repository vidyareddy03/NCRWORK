#include<iostream>

using namespace std;
struct node
{
	int coff;
	int pow;
	struct node *next;
};
class poly
{
public:
	struct node *start;
	poly()
	{
		start = NULL;
	}
	~poly()
	{
		struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
	void Insert_Last(int,int);
	void add(poly&, poly&);
	void Travel_forward();
	
};


void poly::Insert_Last(int c,int p)
{
	struct node *temp, *cur;
	temp = new node;
	temp->coff = c;
	temp->pow = p;
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
void poly::Travel_forward()
{
	struct node *cur;
	cur = start;
	while (cur != NULL)
	{
		cout << cur->coff <<"x^"<<cur->pow<<"+";
		cur = cur->next;
	}
}

void poly::add(poly &arr1, poly &arr2)
{
		struct node *c1 = arr1.start;
	struct node *c2 = arr2.start;
	
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->pow > c2->pow)
		{
			Insert_Last(c1->coff, c1->pow);
			c1 = c1->next;
		}
		else if (c2->pow > c1->pow)
			
		{
			Insert_Last(c2->coff, c2->pow);
			c2 = c2->next;
		}
		else
		{
			Insert_Last(c1->coff+c2->coff, c1->pow);
			c1 = c1->next;
			c2 = c2->next;
		}
		
	}
	while (c1 != NULL)
	{
		Insert_Last(c1->coff, c1->pow);
		c1 = c1->next;
		
	}
	while (c2 != NULL)
	{
		Insert_Last(c2->coff, c2->pow);
		c2 = c2->next;
		

	}
	//arr3.Travel_forward();
}

void main()
{
	poly arr1,arr2,arr3;
	int i,e, n, choice, p, loc,cof;
	char c;
	cout << "enter the number of elements in list1 ";
	cin >> n;
	cout << "enter the elements in list1 ";
	for (i = 0; i < n; i++)
	{ 
		cout << "enter cofficent ";
		cin >> cof;
		cout << "enter power in decreasing order ";
		cin >> p;
		arr1.Insert_Last(cof,p);
	}
	cout << "enter the number of elements in list2 ";
	cin >> n;
	cout << "enter the elements in list2 ";
	for (i = 0; i < n; i++)
	{
		cout << "enter cofficent ";
		cin >> cof;
		cout << "enter power in decreasing order ";
		cin >> p;
		arr2.Insert_Last(cof, p);
	}
	arr1.Travel_forward();
	cout << endl;
	arr2.Travel_forward();
	cout << endl;
	arr3.add(arr1, arr2);
	arr3.Travel_forward();
	system("pause");

}
