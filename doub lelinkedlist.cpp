#include <iostream>
using namespace std;
struct node
{
	int data;
	node *prev;
	node *next;

	node()
	{
		data = 0;
		prev = NULL;
		next = NULL;
	}
};
class doublell
{
public:
	node *head;
	doublell()
	{
		head = NULL;
	}

	int length()
	{
		int count = 0;
		node *temp = head;
		if (head == NULL)
			return 0;
		else
		{
			while (temp != NULL)
			{
				count++;
				temp = temp->next;
			}
			return count;
		}
	}

	void insertatbegin(int data)
	{
		node *temp = new node();
		temp->prev = NULL;
		temp->next = head;
		head = temp;
		temp->data = data;
	}

	void insertatend(int data)
	{
		node *temp = new node();
		temp->data = data;
		temp->next = NULL;
		node *curr;
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		temp->prev = curr;
		curr->next = temp;
	}

	void deleteatbegin()
	{
		if (head == NULL)
		{
			cout << "list is empty" << endl;
			return;
		}
		else
		{
			node *temp = head;
			node *temp1 = temp->next;
			temp1->prev = NULL;
			head = temp1;
			delete (temp);
		}
	}

	void delete_at_pos(int pos)
	{
		int count1 = 0;
		if (pos > length())
		{
			cout << "wrong position" << endl;
		}
		else if (pos == 1)
			deleteatbegin();
		else if (pos == length())
			deleteatend();
		else
		{
			node *slow = head;
			node *fast = head->next;
			while (fast->next != NULL)
			{
				count1++;
				if (count1 + 1 == pos)
				{
					break;
				}
				slow = slow->next;
				fast = fast->next;
			}
			slow->next = fast->next;
			delete (fast);
		}
	}

	void deleteatend()
	{
		if (head == NULL)
		{
			cout << "list is empty";
			return;
		}
		else
		{
			node *temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NULL;
		}
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
	doublell d;
	int ch;
	int v;
	while (true)
	{
		cout << "1.insertbegin\n 2.insertend 3.deletebegin\n 4.deleteend\n 5.length\n 6.exit\n 7.delete_at_pos\n 8.display\n " << endl;
		cout << "Enter your choice:" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter data to insert:" << endl;
			cin >> v;
			d.insertatbegin(v);
			break;
		case 2:
			cout << "Enter data to insert at end:" << endl;
			cin >> v;
			d.insertatend(v);
			break;
		case 3:
			d.deleteatbegin();
			break;
		case 4:
			d.deleteatend();
			break;
		case 5:
			cout << "length of linked list:" << d.length() << endl;
			break;
		case 6:
			exit(0);
			break;
		case 7:
			int pos;
			cout << "Eneter position of node to delete:" << endl;
			cin >> pos;
			d.delete_at_pos(pos);
			break;
		case 8:
			d.display();
			cout << endl;
			break;
		}
	}
}