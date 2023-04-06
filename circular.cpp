#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
node *tail=NULL;
int Length()
{
    node *temp = head;
    int count;
    
    return count;
}
void insert(int element,int founddata) // insert at begin//given a data which you want to insert
{
    node *temp = new node;
    temp->data=element;
    if(tail==NULL){
        node *newnode=new node;
        newnode->data=element;
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        node *find=tail;
        while(find->data!=founddata){
            find=find->next;
        }
        temp->next=find->next;
        find->next=temp;    
        // find->next=temp;
        // temp->next=find;
        tail = temp;
    }   
}
void pariticularIndex(int position, int element)
{
}
void EnsertAtEnd(int element)
{
}
void traverseReverse()
{
}
void deletelist(int position)
{
}
void search(int element)
{
    
}
void print()
{
  node *t=tail;
  do{
    cout<<t->data<<" ";
    t=t->next;
  }while(t!=tail);
  cout<<endl;
}
int main()
{
    while (1)
    {
        cout << "1.Enter the number: " << endl;
        cout << "2.print:--" << endl;
        cout << "4.search " << endl;
        cout << "5.delete at particular Index--(s to l) : " << endl;
        cout << "7.traverse reverse ;  " << endl;
        cout << "8.exit " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int element,give;
            cout << "Emter the element At Begning : ";
            cin >> element;
            cout<<"Enter the element where you want to insert  ";
            cin>>give;
            insert(element,give);
            break;
        case 2:
            print();
            break;
        case 3:
            int position;
            cout << "Enter position bteween: 1 to " << Length() - 1 << " :" << endl;
            cout << "enter the  position : ";
            cin >> position;
            cout << "Enter The element ";
            cin >> element;
            if (position >= 1 && position <= Length())
            {
                pariticularIndex(position, element);
            }
            else
            {
                cout << "You Enter worng input : " << endl;
            }
            break;
        case 4:
            cout << "enter the number : ";
            cin >> element;
            search(element);
            break;
        case 5:
            cout << "Enter position bteween: 1 to " << Length() - 1 << " :" << endl;
            cout << "Enter the podsition : ";
            cin >> position;
            deletelist(position);
            break;
        case 6:
            cout << "enter the element : ";
            cin >> element;
            EnsertAtEnd(element);
            break;
        case 7:
            traverseReverse();
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << "Invalid choice ...- " << endl;
        }
    }
}
