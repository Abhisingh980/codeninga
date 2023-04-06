// merge sort for linked list
#include <iostream>
using namespace std;

// Link list node
class Node
{
public:
    int data;
    Node *next;
};

// Function to merge two sorted linked list
Node *mergeSortedList(Node *head1, Node *head2)
{
    Node *newHead = NULL;
    Node *tail = NULL;

    // Pick either head1 or head2 to make new head
    if (head1->data <= head2->data)
    {
        newHead = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        head2 = head2->next;
    }
    tail = newHead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    if (head1 != NULL)
    {
        tail->next = head1;
    }
    if (head2 != NULL)
    {
        tail->next = head2;
    }

    return newHead;
}

// function to calculate the mid of a linked list
Node *middle(Node *head)
{
    Node *mid = head;
    Node *tail = head->next;

    while (mid->next != NULL && (tail != NULL && tail->next != NULL))
    {
        mid = mid->next;
        tail = tail->next->next;
    }
    return mid;
}

Node *mergeSort(Node *head)
{

    // Base case:- if size of linked list is 0 or 1
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Creating node to store mid of linked list
    Node *mid = new Node();

    mid = middle(head);

    Node *head2 = mid->next;

    mid->next = NULL;

    Node *newHead = mergeSortedList(mergeSort(head), mergeSort(head2));

    return newHead;
}

// Function to insert a node at the beginning of the linked list
void push(Node **head_ref, int newdata)
{
    // allocate memoray for new node
    Node *newNode = new Node();

    // put the data in new node
    newNode->data = newdata;

    // link the list to the new node
    newNode->next = (*head_ref);

    // update the head
    (*head_ref) = newNode;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    // creating a unsorted list
    // to test out the function
    // list: 40->25->2->10->7->1
    push(&head, 1);
    push(&head, 7);
    push(&head, 10);
    push(&head, 2);
    push(&head, 25);
    push(&head, 40);

    cout << "Linked list before sorting: " << endl;
    printList(head);

    Node *newHead = mergeSort(head);

    cout << "Linked list after sorting: " << endl;
    printList(newHead);
}