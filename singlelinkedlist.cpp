#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(int value)
	{
		data = value;
		next = NULL;
	}
};
class linkedlist
{
public:
	node *head;
	linkedlist()
	{
		head = NULL;
	}
	int length()
	{
		node *temp = head;
		int count = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
	bool isEmpty()
	{
		return head == NULL;
	}

	void insertatbegin(int d)
	{
		node *nn = new node(d);
		if (head == NULL)
		{
			head = nn;
		}
		else
		{
			nn->next=head;
			head=nn;
		}
	}

	bool insertatend(int d)
	{
		node *nn = new node(d);
		if (head==NULL)
		{
			head=nn;
			return true;
		}
		else
		{node* temp=head;
			while (temp->next!= NULL)
			{
				temp = temp->next;
			}
			temp->next = nn;
		}
		return true;
	}

	void deleteatbegin()
	{
		node *temp;
		if (isEmpty())
		{
			return;
		}
		else
		{
			temp = head;
			head = head->next;
			delete (temp);
		}
		return;
	}

	void deleteatend()
	{
		node *temp = head;
		node *rn;
		if (isEmpty())
		{
			return;
		}
		if (length() == 1)
		{
			delete (head);
			head = NULL;
			return;
		}
		else
		{
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			rn = temp->next;
			temp->next = NULL;
			delete (rn);
		}
		return;
	}

	void display()
	{
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
	}
};

int main()
{
	int ch;
	linkedlist l;
	while (true)
	{
		cout << " 1.insertbegin\n 2.insertend\n 3.deletebegin\n 4.deleteend\n 5.display\n 6.length\n 7.exit\n";
		cout << "Enter your operation : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			int d;
			cout << "Enter data to insert : ";
			cin >> d;
			l.insertatbegin(d);
			break;
		case 2:
			int a;
			cout << "Enter data to insert at end : ";
			cin >> a;
			l.insertatend(a);
			break;
		case 3:
			l.deleteatbegin();
			cout << endl;
			break;
		case 4:
			l.deleteatend();
			cout << endl;
			break;
		case 5:
			cout << "Elements of linked list are : ";
			l.display();
			cout << endl;
			break;
		case 6:
			cout << "length of linked list is: " << l.length();
			cout << endl;
			break;
		case 7:
			exit(0);
			break;
		}
	}
}