#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
                int data;
                Node *next;
                Node(int data)
                {
                        this->data = data;
                        this->next = NULL;
                }
        };

*****************************************************************/

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    // Write your code here
    Node *FT = NULL;
    Node *FH = NULL;
    if (head1->data < head2->data)
    {
        FH = head1;
        FT = head1;
        head1 = head1->next;
    }
    else
    {
        FH = head2;
        FT = head2;
        head2 = head2->next;
    }
    while (head1->next != NULL && head2->next != NULL)
    {
        if (head1->data > head2->data)
        {
            FT->next = head2;
            FT = head2;
            head2 = head2->next;
        }
        else
        {
            FT->next = head1;
            FT = head1;
            head1 = head1->next;
        }
    }
    if (head2->next == NULL)
    {
        head1->next = head2;
        return FT;
    }
    else
    {
        if (head1->next == NULL)
            head2->next = head1;
        return FT;
    }
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}