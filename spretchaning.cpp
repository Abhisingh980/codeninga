#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() {}
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class spreatechaining : public Node
{
    Node **arr;
    int capacity;

public:
    spreatechaining(int size)
    {
        capacity = size;
        arr = new Node *[size];
    }
    void Insert(int);
    void Delete(int);
    bool Serach(int);
    void print();
};
void spreatechaining::Insert(int key)
{
    int index = key % capacity;
    if (arr[index] == NULL)
    {
        arr[index] = (new Node(key));
        return;
    }
    else
    {
        Node *temp = arr[index];
        Node *newNode = new Node(key);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void spreatechaining::Delete(int key)
{
    int index = key % capacity;
    if (arr[index] == NULL)
    {
        cout << "key is Not found --" << endl;
        return;
    }
    else
    {
        Node *temp = arr[index];
        if (temp->data == key)
        {
            arr[index]=temp->next;
            cout << "key deleted -" << endl;
            return;
        }
        Node *fast = arr[index]->next;
        while (fast->next != NULL)
        {
            if (fast->data == key)
            {
                temp->next = fast->next;
                delete (fast);
                cout << "key deleted --" << endl;
                return;
            }
            temp = temp->next;
            fast = fast->next;
        }
        if (fast->data == key && fast->next == NULL)
        {
            temp->next = fast->next;
            delete (fast);
            cout << "key deleted --" << endl;
            return;
        }
    }
}
bool spreatechaining::Serach(int key)
{
    int index = key % capacity;
    if (arr[index] == NULL)
    {
        return false;
    }
    else if (arr[index]->data == key)
    {
        return true;
    }
    else
    {
        Node *temp = arr[index];
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}
void spreatechaining::print()
{
    for (int i = 0; i < 10; i++)
    {
        Node *temp = arr[i];
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "NULL";
            }
        }
        cout << endl;
    }
}
int main()
{
    spreatechaining s(10);
    while (1)
    {
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Serach" << endl;
        cout << "4.Print" << endl;
        cout << "5.Exit" << endl;
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int key;
            cout << "Enter the key : ";
            cin >> key;
            s.Insert(key);
            break;
        case 2:
            int key1;
            cout << "Enter the key : ";
            cin >> key1;
            s.Delete(key1);
            break;
        case 3:
            int key2;
            cout << "Enter the key  ";
            cin >> key2;
            if (s.Serach(key2))
            {
                cout << "key found --" << endl;
            }
            else
            {
                cout << "key Not found -" << endl;
            }
            break;
        case 4:
            s.print();
            cout << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}