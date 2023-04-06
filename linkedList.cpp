#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = NULL;
void insertBegain(int element)
{
    node *temp = new node;
    temp->data = element;
    temp->next = head;
    head = temp;
}
void pariticularIndex(int position, int element)
{
    if(element==1){
        insertBegain(element);
    }
    else{
    node *temp1 = new node;
    temp1->data = element;
    temp1->next = NULL;
    node *p=head;
    for(int i=1;i<=position-1;i++){//node Search
       if(i==position){ 
          break;
       }
       p=p->next;
    }
    temp1->next=p->next;
    p->next=temp1;
    }
}
int Length()
{
    node *temp = head;
    int count;
    if(head != NULL)
     count = 1;
     else 
     count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void search(int element)
{
    node *find = head;
    int flag = 0;
    while (find != NULL)
    {
        if (element == find->data)
        {
            flag = 1;
           cout << element << " <--prev :  match found : ->" << find->data << endl;
        }
        find=find->next;
    }
    if(flag==0){
        cout<<"not Matached : "<<endl;
    }
}
void deletelist(int position){
    if(position==1){//deletion front position
        node *ptr=head;
        head=head->next;
        delete ptr;
    }
    else{//deletiion in middle
     node *ptr=head;
     node *p3=head->next;
    for(int i=1;i<position-1;i++){
    ptr = ptr->next;
    p3=p3->next;
    }
     ptr->next=p3->next;
     delete p3;
    }
    

}
void EnsertAtEnd(int element){
    node *End=new node;
    End->data=element;
    End->next=NULL;
    node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=End;

}
void print()
{
    node *temp=head;
    if (temp == NULL)
    {
        cout << "List is empty : " << endl;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    while (1)
    {
        cout << "1.Enter the number: " << endl;
        cout << "2.print:--" << endl;
        cout << "3.Enseret in Between to last at particular index :" << endl;
        cout << "4.search " << endl;
        cout << "5.delete at particular Index--(s to l) : " << endl;
        cout<<  "6.Ensert at Last ::---:  "<<endl;
        cout << "7.exit " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int element;
            cout << "Emter the element At Begning : ";
            cin >> element;
            insertBegain(element);
            break;
        case 2:
            print();
            break;
        case 3:
            int position;
            cout << "Enter position bteween: 1 to " << Length()-1 << " :" << endl;
            cout << "enter the  position : ";
            cin >> position;
            cout << "Enter The element ";
            cin >> element;
            if(position>=1&&position<=Length()){
            pariticularIndex(position, element);
            }else{
                cout<<"You Enter worng input : "<<endl;
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
           cout<<"enter the element : ";
           cin>>element;
           EnsertAtEnd(element);
           break; 
        case 7:
            exit(1);
            break;
        default:
            cout << "Invalid choice ...- " << endl;
        }
    }
}
