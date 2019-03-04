#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};
class BST
{
	
public:
	struct node *start;
	BST()
	{
		start = NULL;
	}
	//for deallocating node postfix bcz we canot travel for parent if we delete first parent 
	void deletenode(node * cur)
	{
		if (cur != NULL)
		{
			deletenode(cur->left);
			deletenode(cur->right);
			delete cur;
		}
	}
	~BST()
	{
		if (start != NULL)
		{
			deletenode(start);
		}

	}

	node* insert(int,node*);
	node* delete_spec(int,node*);
	void inorder();
	void preorder();
	void postorder();
	int findmax(node *);
	int findmin(node *);
	int height(node*);
	int nonLeafNodesCount(node *);
	int LeafNodesCount(node *);
	friend void printIn(node *);
	friend void printPre(node *);
	friend void printPost(node *);
};
int BST::LeafNodesCount(node * cur)
{
	if (cur == NULL)
		return 0;
	if (cur->left == NULL&&cur->right == NULL)
		return 1;
	return (LeafNodesCount(cur->left) + LeafNodesCount(cur->right));

}

int BST::nonLeafNodesCount(node* cur)
{
	if (cur == NULL)
		return 0;
	if (cur->left == NULL && cur->right == NULL)
		return 0;
	return(nonLeafNodesCount(cur->left) + nonLeafNodesCount(cur->right)+1);
}

int BST::findmin(node * cur)
{
	if (cur != NULL)
	{
		while (cur->left != NULL)
			cur = cur->left;
		return cur->data;
	}
	else
		return -1;
}
int BST::findmax(node* cur)
{
	if (cur != NULL)
	{
		while (cur->right != NULL)
			cur = cur->right;
		return cur->data;
	}
	return -1;
}

int BST::height(node* cur )
{ 
	
	
	if (cur == NULL)
		return -1;
	return(max(height(cur->left), height(cur->right)) + 1);
}

void BST::inorder()
{
	if (start != NULL)
		printIn(start);
}
void printIn(node * cur)
{
	if (cur != NULL)
	{
		printIn(cur->left);
		cout << cur->data << " ";
		printIn(cur->right);

	}
}

void BST::preorder()
{
	if (start != NULL)
		printPre(start);
}
void printPre(node * cur)
{
	if (cur != NULL)
	{
		cout << cur->data << " ";
		printPre(cur->left);
		printPre(cur->right);

	}
}

void BST::postorder()
{
	if (start != NULL)
		printPost(start);
}
void printPost(node * cur)
{
	if (cur != NULL)
	{
		printPost(cur->left);
		printPost(cur->right);
		cout << cur->data << " ";

	}
}

node* BST::insert(int ele, node *cur)
{
	if (cur == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (ele < cur->data)
			cur->left = insert(ele, cur->left);
		else
			cur->right = insert(ele, cur->right);
		return cur;
	}
}

node* BST::delete_spec(int ele, node* cur)
{
	if (cur != NULL)
	{
		if (ele > cur->data)
			cur->right = delete_spec(ele, cur->right);
		else
			if (ele < cur->data)
				cur->left = delete_spec(ele, cur->left);

			else
			{
				//when two children
				if (cur->left != NULL&&cur->right != NULL)
				{
					cur->data = findmax(cur->left);
					cur->left = delete_spec(cur->data, cur->left);
				}
				else
				{
					//when one or no children
					struct node  *temp;
					temp = cur;
					if (cur->left == NULL)
						cur = cur->right;
					else
						cur = cur->left;
					delete temp;
				}
				return cur;
			}
	}
}

void main()
{
BST arr;
int e, n, choice, p,count=0;
char c;

do
{
	cout << "1.insert 2.delete specific element  3.inorder  4.preorder  5.postorder "<<endl<<"6.findmin  7.findmax  8.height  9.leafnodes count  10.nonleafnodes count";
	cin >> choice;
	switch (choice)
	{
	case 1: cout << "enter element to insert ";
		cin >> e;
		arr.start=arr.insert(e,arr.start);
		break;
	case 2:
		cout << "enter  element to be deleted "  << endl;
		cin >> e;
		arr.start=arr.delete_spec(e, arr.start);
//		cout << "deleted element is " << arr.start->data;
		break;
	case 3:arr.inorder(); break;
	case 4:arr.preorder(); break;
	case 5:arr.postorder(); break;
	case 6:count=arr.findmin(arr.start);
		cout << "min element is " << count << endl; break;
	case 7:count=arr.findmax(arr.start);
		cout << "max element is " << count; break;
	case 8:
		count = arr.height(arr.start);
		cout << "height is " << count << endl; break;
	case 9:count=arr.LeafNodesCount(arr.start);
		cout << "number of leaf nodes are " << count << endl; break;
	case 10:count=arr.nonLeafNodesCount(arr.start);
		cout << "number of non leaf nodes are " << count << endl;
		break;
	default:cout << "enter the wrong choice"; break;
	}
	cout << "do yo want to continue (y/n)";
	cin >> c;


} while (c == 'y' || c == 'Y');



system("pause");
}