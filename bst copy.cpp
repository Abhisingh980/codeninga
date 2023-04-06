#include <iostream>
using namespace std;
class node
{
public:
	int value;
	node *left;
	node *right;

	node()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}
	node(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}
};
class bst
{
public:
	node *root;
	bst()
	{
		root = NULL;
	}
	// insert
	void insert(node *curr)
	{
		if (root == NULL)
		{
			root = curr;
			cout << "value inserted ";
		}
		else
		{
			node *temp = root;
			while (temp != NULL)
			{
				if (temp->value > curr->value && temp->left == NULL)
				{
					temp->left = curr;
					cout << "value inserted left";
					break;
				}
				else if (temp->value > curr->value)
				{
					temp = temp->left;
				}
				else if (temp->value < curr->value && temp->right == NULL)
				{
					temp->right = curr;
					cout << "value inserted right";
					break;
				}
				else if (temp->value == curr->value)
				{
					cout << "duplicates are not allowed";
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
	// search
	bool search(int v)
	{
		if (root == NULL)
		{
			cout << "tree is empty";
			return false;
		}
		else
		{
			node *temp = root;
			while (temp != NULL)
			{
				if (v == temp->value)
					return true;
				else if (v > temp->value)
					temp = temp->right;
				else
					temp = temp->left;
			}
			return false;
		}
	}

	// height of tree
	int height(node *r)
	{
		if (r == NULL)
			return -1;
		else
		{
			int lheight = height(r->left);
			int rheight = height(r->right);
			if (lheight > rheight)
			{
				return (lheight + 1);
			}
			else
			{
				return (rheight + 1);
			}
		}
	}
	// level order
	void printgivenlevel(node *curr, int level)
	{
		if (curr == NULL)
			return;
		else if (level == 0)
		{
			cout << curr->value << " ";
		}
		else
		{
			printgivenlevel(curr->left, level - 1);
			printgivenlevel(curr->right, level - 1);
		}
	}
	void levelorderBFS(node *r)
	{
		int h = height(r);
		for (int i = 0; i <= h; i++)
			printgivenlevel(r, i);
	}

	void preorder(node *curr)
	{
		if (curr == NULL)
			return;
		else
		{
			cout << curr->value << " ";
			preorder(curr->left);
			preorder(curr->right);
		}
	}

	void inorder(node *r)
	{
		node *temp = r;
		if (temp->left != NULL)
		{
			inorder(temp->left);
		}
		cout << temp->value << " ";
		if (temp->right != NULL)
			inorder(temp->right);
	}

	void postorder(node *curr)
	{
		if (curr == NULL)
			return;
		else
		{
			postorder(curr->left);
			postorder(curr->right);
			cout << curr->value << " ";
		}
	}

	node *minValueNode(node *curr)
	{
		node *temp = curr;
		if (temp == NULL)
			return NULL;
		else
		{
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			return temp;
		}
	}

	node *deleteNode(node *r, int v)
	{
		if (r == NULL)
			return r;
		else if (v < r->value)
		{
			r->left = deleteNode(r->left, v);
		}
		else if (v > r->value)
		{
			r->right = deleteNode(r->right, v);
		}
		else
		{
			if (r->left == NULL)
			{
				node *temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == NULL)
			{
				node *temp = r->left;
				delete r;
				return temp;
			}
			else
			{
				node *temp = minValueNode(r->right);
				r->value = temp->value;
				deleteNode(r->right, temp->value);
			}
		}
		return r;
	}
};
int main()
{
	int ch;
	int val, v;
	bst b;
	while (true)
	{
		cout << "\n1.insert 2.delete 3.search 4.height 5.traversal 6.lebelorder 7exit" << endl;
		cout << "Enter the operation" << endl;
		cin >> ch;
		node *r = new node();
		switch (ch)
		{
		case 1:
			cout << "enter value to insert" << endl;
			cin >> val;
			r->value = val;
			b.insert(r);
			break;
		case 2:
			cout << "enter value to delete " << endl;
			cin >> v;
			r->value = v;
			if (b.root != NULL)
			{
				b.deleteNode(b.root, v);
				cout << "value deleted" << endl;
			}
			else
			{
				cout << "value not found";
			}
			break;
		case 3:
			cout << "Enter element to search" << endl;
			cin >> v;
			if (b.search(v))
			{
				cout << "value found";
			}
			else
			{
				cout << "value not found";
			}
			break;
		case 4:
			// r=root;
			cout << "height of tree is:" << b.height(b.root);
			break;
		case 5:
			cout << "preorder traversal of bst : ";
			b.preorder(b.root);
			cout << endl;
			cout << "inorder traversal of tree : ";
			b.inorder(b.root);
			cout << endl;
			cout << "postorder traversal of bst : ";
			b.postorder(b.root);
			break;
		case 6:
			cout << "level order of bst is: " << endl;
			b.levelorderBFS(b.root);
			break;
		case 7:
			exit(0);
		default:
			cout << "invalid choice";
		}
	}
}
