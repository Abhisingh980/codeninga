#include <iostream>
using namespace std;
class hashliner
{
    int *data;
    int count;
    int capacity;

public:
    hashliner(){}
    hashliner(int size)
    {
        count=0;
        data = new int[size];
        capacity=size;
        // initializing array with -1
        for (int i = 0; i < capacity; i++)
        {
            data[i] = -1;
        }
    }
    void Insert(int);
    void Delete(int);
    void search(int);
};
void hashliner::Insert(int key)
{
    // index probing
    int index = key % capacity;
    while (data[index] != -1)
    {
        index = (index + 1) % capacity;
    }
    data[index] = key;
    count++;
}
void hashliner::Delete(int key)
{
    int size=0;
    int index = key % capacity;
    if (data[index] == key)
    {
        data[index] = -1;
        cout << "data deleted : " << endl;
        return;
    }
    else
    {
        while (data[index] != -1 && count !=size)
        {
            size+=1;
            index = (index + 1) % capacity;
            if (data[index] == key)
            {
                data[index] = -1;
                cout << "data deleted : " << endl;
                return;
            }
        }
    }
    if(count== size||data[index]==-1){
        cout<<"data is not found : "<<endl;
        return;
    }
}
void hashliner::search(int key)
{
    int size=0;
    int index = key % capacity;
    if (data[index] == key)
    {
        cout << "value at index : "<<index<<" :"<< endl;
        return;
    }
    else
    {
        while (data[index] != -1 && count != size)
        {
            size += 1;
            index = (index + 1) % capacity;
            if (data[index] == key)
            {
                cout << "value at index : "<<index<<" :"<< endl;
                  return;
            }
        }
    }
    if(count==size||data[index]==-1){
        cout<<"data not found "<<endl;
        return;
    }
}
int main()
{
    hashliner h(10);
    while (1)
    {
        int choice;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Exit" << endl;
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
            break;
        }
        case 4:
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