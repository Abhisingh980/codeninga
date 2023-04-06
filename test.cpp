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

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    cout<<"enter the data : ";
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
Node *insertNode(Node *head, int i, int data)
{
    // Write your code here
    Node *temp = head;
    Node *temp1;
    temp1->data = data;
    int c = 0;
    if (temp == NULL)
    {
        return head;
    }
    else
    {
        c++;
        if (c + 1 == i)
        {
            temp->next = temp1;
            temp1->next = temp->next;
        }
        temp = insertNode(temp->next, i, data);
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

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos, data;
        cout<<"pos of the data and data : ";  
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}