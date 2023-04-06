#include <iostream>
#include <string>
using namespace std;
template <typename S>
class stack
{
    int top;
    S st[1000];

public:
    stack()
    {
        top = -1;
    }
    void pop();
    void push(S);
    S Top();
    int Size();
    bool Empty();
    void print();
};
template <typename S>
void stack<S>::pop()
{
    if (top == -1)
        cout << "Stack is empty" << endl;
    else
        cout << "Element popped is " << st[top] << endl;
    top--;
}
template <typename S>
void stack<S>::push(S x)
{
    if (top == 100000000)
        cout << "Stack is full" << endl;
    else
        top++;
    st[top] = x;
}
template <typename S>
bool stack<S>::Empty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename S>
S stack<S>::Top()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        return st[top];
    }
    return 0;
}
template <typename S>
int stack<S>::Size()
{
    return top + 1;
}
template <typename S>
void stack<S>::print()
{
    if (Empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << st[i] << " ";
        }
    }
}
int main()
{
    stack<int> s;
    while (1)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Size" << endl;
        cout << "5. Empty" << endl;
        cout << "6. Print" << endl;
        cout << "7. Exit" << endl;
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter element to push : ";
            cin >> x;
            s.push(x);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout <<" top elemenet of the stack is : "<<s.Top() << endl;
            break;
        case 4:
            cout <<"Size is : "<<s.Size() << endl;
            break;
        case 5:
            if (s.Empty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 6:
            s.print();
            cout << endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}