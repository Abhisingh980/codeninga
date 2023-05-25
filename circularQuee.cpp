#include <iostream>
using namespace std;
class Queue
{
    int store[10];
    int front;
    int rear;
    int size;

public:
    Queue( int size = 10)
    {
        for (int i = 0; i < 10; i++)
        {
            store[i] = -1;
        }
        front = -1;
        rear = -1;
        this->size = size;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if ((rear + 1) % 10 == front)
        {
            return true;
        }
        return false;
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (rear == 10)
        {
            rear = 0;
        }
        rear = (rear + 1 )% 10;
        store[rear] = data;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (front == 9)
        {
            front = 0;
        }
        front = (front + 1) % 10;
        int data = store[front];
        store[front] = -1;
        return data;
    }
    void print()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << store[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    while (1)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            cout << q.dequeue() << endl;
            break;
        case 3:
            q.print();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}