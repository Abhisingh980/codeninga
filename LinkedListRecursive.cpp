#include <iostream>
using namespace std;
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
Node *deleteNode(Node *head, int i)
{
    // Write your code here
    Node *temp = head;
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
            temp->next = temp->next->next;
        }
        temp = deleteNode(temp->next, i);
    }
    return head;
}
Node *appendLastNToFirst(Node *head, int n)
{
    // Write your code here
    Node *temp = head;
    Node *temp1 = head;
    int c = 0;
    if (temp == NULL)
    {
        return head;
    }
    else
    {
        c++;
        if (c == n)
        {
            temp1 = temp->next;
            temp->next = NULL;
            temp = temp1;
        }
        temp = appendLastNToFirst(temp->next, n);
    }
    return head;
}
Node *reverseLinkedList(Node *head)
{
    // Write your code here
    Node *temp = head;
    Node *temp1 = head;
    if (temp == NULL)
    {
        return head;
    }
    else
    {
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = temp;
        temp = temp1;
        temp = reverseLinkedList(temp->next);
    }
    return head;
}
int length(Node *head)
{
    // Write your code here
    Node *temp = head;
    int len=0;
    if (temp == NULL)
    {
        return len;
    }
    else
    {
        len = length(temp->next);
    }
    return len+1    ;
}
int main(){
    while(1){
        cout<<"enter the list : "<<endl;
        
        cout<<"enter the choice : ";
        int choice;
        cin>>choice;

    }
}