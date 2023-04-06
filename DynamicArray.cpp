#include <iostream>
using namespace std;
class DynamicArray
{
    int *temp;
    int capacity;
    int count;

public:
    DynamicArray()
    {
        temp = new int[5];
        count = 0;
        capacity = 5;
    }
    void Insert(int);
    int get(int);
    void addpartcularindex(int, int);
    void Print();
    int CapacityIndex()
    {
        return capacity;
    }
    int Counter()
    {
        return count;
    }
};
void DynamicArray::Insert(int value)
{
    if (count == capacity)
    {
        int *newTemp = new int[2 * count];
        for (int i = 0; i < count; i++)
        {
            newTemp[i] = temp[i];
        }
        newTemp[count] = value;
        count++;
        capacity *= 2;
        delete[] temp;
        temp = newTemp;
    }
    else
    {
        temp[count] = value;
        count++;
    }
}
int DynamicArray::get(int i)
{
    if (i < capacity)
    {
        return temp[i];
    }
    else
    {
        return -1;
    }
}
void DynamicArray::addpartcularindex(int i, int value)
{
    if (i >= count && i < capacity)
    {
        Insert(value);
    }
    else
    {
        cout << " Enter the validd Index :XXXXXX?" << endl;
        return;
    }
}
void DynamicArray::Print()
{
    for (int i = 0; i < count; i++)
    {
        cout << temp[i] << " ";
    }
}
int main()
{
    DynamicArray DA;
    while (1)
    {
        cout << "1.Insert" << endl;
        cout << "2.get value at particular index" << endl;
        cout << "3.insert at particular Index" << endl;
        cout << "4.print" << endl;
        cout << "5.exit" << endl;
        int choice;
        cout << "Enter the choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter The value  : ";
            cin >> value;
            DA.Insert(value);
            break;
        case 2:
            int index;
            cout << "Enter The index between 0 to " << DA.Counter() << " : ";
            cin >> index;
            cout << DA.get(index) << endl;
            ;
            break;
        case 3:
            int index1, value1;
            cout << "Enter The index between " << DA.Counter() << " to " << DA.CapacityIndex() << " : ";
            cin >> index1;
            cout << "Enter the value : ";
            cin >> value1;
            DA.addpartcularindex(index1, value1);
            break;
        case 4:
            DA.Print();
            cout << endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << " Inter  a valid choice : " << endl;
        }
    }
}