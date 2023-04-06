#include <iostream>
using namespace std;
class BTS
{
    int data;
    BTS *left,*right;
    public:
    bool Searching(int);
    void Insertion(int);
    void Deation(int);
    int max();
    int min();
    void print();
    BTS()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
    BTS(int n)
    {
        data=n;
        left=NULL;
        right=NULL;
    }
};
bool BTS::Searching(int n)
{
    if(data==n)
    {
        cout<<"The value is found : "<<endl;
        return true;
    }
    else if(data>n)
    {
        if(left!=NULL)
        {
            left->Searching(n);
        }
        else
        {
            cout<<"The value is not found : "<<endl;
            return false;
        }
    }
    else
    {
        if(right!=NULL)
        {
            right->Searching(n);
        }
        else
        {
            cout<<"The value is not found : "<<endl;
            return false;
        }
    }
    return false;
}
void BTS::Insertion(int n)
{
    if(data==0)
    {
        data=n;
        cout<<"The value is inserted : "<<endl;
    }
    else if(data>n)
    {
        if(left!=NULL)
        {
            left->Insertion(n);
        }
        else
        {
            left=new BTS(n);
            cout<<"The value is inserted : "<<endl;
        }
    }
    else
    {
        if(right!=NULL)
        {
            right->Insertion(n);
        }
        else
        {
            right=new BTS(n);
            cout<<"The value is inserted : "<<endl;
        }
    }
}
void BTS::Deation(int n)
{
    if(data==n)
    {
        if(left==NULL && right==NULL)
        {
            data=0;
            cout<<"The value is deleted : "<<endl;
        }
        else if(left==NULL)
        {
            BTS *temp=right;
            data=temp->data;
            right=temp->right;
            left=temp->left;
            delete temp;
            cout<<"The value is deleted : "<<endl;
        }
        else if(right==NULL)
        {
            BTS *temp=left;
            data=temp->data;
            right=temp->right;
            left=temp->left;
            delete temp;
            cout<<"The value is deleted : "<<endl;
        }
        else
        {
            BTS *temp=right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            data=temp->data;
            temp->data=n;
            right->Deation(n);
            cout<<"The value is deleted : "<<endl;
        }
    }
    else if(data>n)
    {
        if(left!=NULL)
        {
            left->Deation(n);
        }
        else
        {
            cout<<"The value is not found : "<<endl;
        }
    }
    else
    {
        if(right!=NULL)
        {
            right->Deation(n);
        }
        else
        {
            cout<<"The value is not found : "<<endl;
        }
    }
}
int BTS::max()
{
    if(right!=NULL)
    {
        right->max();
    }
    else
    {
        return data;
    }
    return data;
}
int BTS::min()
{
    if(left!=NULL)
    {
        left->min();
    }
    else
    {
        return data;
    }
    return data;
}
void BTS::print()
{
    if(left!=NULL)
    {
        left->print();
    }
    cout<<data<<" ";
    if(right!=NULL)
    {
        right->print();
    }
}
int main()
{
    BTS b;
    int max,min;
    cout<<endl;
    while (1)
    {
        cout << "Enter the case : "<<endl;
        cout << "--------------------------------------"<<endl;
        cout << "1.Searching" << endl;
        cout << "2.Insertion " << endl;
        cout << "3.Delation" << endl;
        cout << "4.max" << endl;
        cout << "5.min" << endl;
        cout << "6.print"<<endl;
        cout << "7.exit" << endl;
        int n;
        cout<<"Enter the option  :";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter the  value : ";
            cin >> n;
            b.Searching(n);
            break;
        case 2:
            cout << "enter the  value : ";
            cin >> n;
            b.Insertion(n);
            break;
        case 3:
            cout << "enter the  value : ";
            cin >> n;
            b.Deation(n);
            break;
        case 4:
            max=b.max();
            cout<<"The max value is : "<<max<<endl;
            break;
        case 5:
             min=b.min();
            cout<<"The min value is : "<<min<<endl;
            break;
        case 6:
         b.print();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Enter the nuber is not match : ";
        }
    }
}