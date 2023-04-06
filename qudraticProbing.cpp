#include <iostream>
using namespace std;
class hashqudratic
{
    int *data;
    int count;
    int capacity;

public:
    hashqudratic()
    {
        count = 0;
        data = new int[101];
        capacity=100;
        // initializing array with -1
        for (int i = 0; i < capacity; i++)
        {
            data[i] = -1;
        }
    }
    void Insert(int);
    void Delete(int);
    void search(int);
    void Print();
};
void hashqudratic::Insert(int key)
{
    // index probing
    int i=0;
    int index = key % 7;
    while (data[index] != -1)
    {
        i++;
        index = (index + i*i) % 7;
    }
    data[index] = key;
    count++;
}
void hashqudratic::Delete(int key)
{
    int size = 0;
    int i=0;
    int index = key % 7;
    if (data[index] == key)
    {
        data[index] = -1;
        cout << "data deleted : " << endl;
        return;
    }
    else
    {
        while (data[index] != -1 && count != size)
        {
            i++;
            size += 1;
            index = (index + i*i) % 7;
            if (data[index] == key)
            {
                data[index] = -1;
                cout << "data deleted : " << endl;
                return;
            }
        }
    }
    if (count == size)
    {
        cout << "data is not found : " << endl;
        return;
    }
}
void hashqudratic::search(int key)
{
    int i=0;
    int size = 0;
    int index = key % 7;
    if (data[index] == key)
    {
        cout << "value at index : " << index << " :" << endl;
        return;
    }
    else
    {
        while (data[index] != -1 && count != size)
        {
            i++;
            size += 1;
            index = (index + i*i) % 7;
            if (data[index] == key)
            {
                cout << "value at index : " << index << " :" << endl;
                return;
            }
        }
    }
    if (count == size || data[index] == -1)
    {
        cout << "data not found " << endl;
        return;
    }
}
void hashqudratic::Print()
{
    for(int i=0;i<7;i++){
        cout<<data[i]<<" ";
    }
}
int main()
{
    hashqudratic h;
    while (1)
    {
        int choice;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Print" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            h.Insert(key);
            break;
        }
        case 2:
        {
            int val;
            cout << "entwr the value you want to delete :";
            cin >> val;
            h.Delete(val);
            break;
        }
        case 3:
        {
            int value;
            cout << " Enter the key :";
            cin >> value;
            h.search(value);
        }
        case 4:
        {
            h.Print();
            cout << endl;
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    }
}