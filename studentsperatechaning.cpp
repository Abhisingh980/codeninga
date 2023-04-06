#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    string rollno;
    Node *next;
    Node() {}
    Node(string sname, string srollno)
    {
        name = sname;
        rollno = srollno;
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
    int hashFunction(string);
    bool Insert(string, string);
    bool Delete(string);
    string Serach(string);
    void print();
    bool check(string);
    ~spreatechaining()
    {
        for (int i = 0; i < 11; i++)
        {
            Node *temp = arr[i];
            while (temp)
            {
                arr[i] = arr[i]->next;
                delete temp;
                temp = arr[i];
            }
        }
    }
};
int spreatechaining::hashFunction(string roll)
{
    int length = roll.length();
    int index = ((10 * (roll[length - 2]) - '0') + (roll[length - 1] - '0'));
    return (index % capacity);
}
bool spreatechaining::check(string roll)
{
    for (int i = 0; i < 11; i++)
    {
        Node *temp = arr[i];
        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                return false;
            }
            temp = temp->next;
        }
    }
    return true;
}
bool spreatechaining::Insert(string sname, string roll)
{
    if (check(roll))
    {
        int index = hashFunction(roll);
        if (arr[index] == NULL)
        {
            arr[index] = (new Node(sname, roll));
            return true;
        }
        else
        {
            Node *temp = arr[index];
            Node *newNode = new Node(sname, roll);
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            return true;
        }
    }
    else
    {
        return false;
    }
}
bool spreatechaining::Delete(string roll)
{
    int index = hashFunction(roll);
    if (arr[index] == NULL)
    {
        cout << "key is Not found --" << endl;
        return false;
    }
    else
    {
        Node *temp = arr[index];
        if (temp->rollno == roll)
        {
            arr[index] = temp->next;
            // cout << "key deleted -" << endl;
            return true;
        }
        Node *fast = arr[index]->next;
        while (fast->next != NULL)
        {
            if (fast->rollno == roll)
            {
                temp->next = fast->next;
                delete (fast);
                // cout << "key deleted --" << endl;
                return true;
            }
            temp = temp->next;
            fast = fast->next;
        }
        if (fast->rollno == roll && fast->next == NULL)
        {
            temp->next = fast->next;
            delete (fast);
            // cout << "key deleted --" << endl;
            return true;
        }
        return false;
    }
}
string spreatechaining::Serach(string roll)
{
    int index = hashFunction(roll);
    if (arr[index] == NULL)
    {
        return "";
    }
    else if (arr[index]->rollno == roll)
    {
        return arr[index]->name;
    }
    else
    {
        Node *temp = arr[index];
        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                return temp->name;
            }
            temp = temp->next;
        }
    }
    return "";
}
void spreatechaining::print()
{
    for (int i = 0; i < 11; i++)
    {
        Node *temp = arr[i];
        while (temp != NULL)
        {
            cout << temp->name << " | " << temp->rollno << " | ->";
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
    spreatechaining s(11);
    string name, roll, roll1, roll2;
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
        system("clear");
        switch (choice)
        {
        case 1:
            cout << "Enter the Name : ";
            cin >> name;
            cout << "Enter the rollno : ";
            cin >> roll;
            if (s.Insert(name, roll))
            {
                cout << "data inserted sucess fully -" << endl;
            }
            else
            {
                cout << "daat not inserted succesfully - " << endl;
            }
            break;
        case 2:
            cout << "Enter the roll-number : ";
            cin >> roll1;
            if (s.Delete(roll1))
            {
                cout << "Deleted data :" << endl;
            }
            else
            {
                cout << "not found data :" << endl;
            }
            break;
        case 3:
            cout << "Enter the roll-number : ";
            cin >> roll2;
            cout << "name of corsponding roll -> " << s.Serach(roll2) << endl;
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