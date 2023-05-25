#include <iostream>
using namespace std;
class SymbolInfo
{
    string name;
    string type;
    SymbolInfo *next;
    public:
    SymbolInfo(string name,string type){
        this->name=name;
        this->type=type;
        next=NULL;
    }
    void setName(string name){
        this->name=name;
    }
    void setType(string type){
        this->type=type;
    }
    void setNext(SymbolInfo *next){
        this->next=next;
    }
    string getName(){
        return name;
    }
    string getType(){
        return type;
    }
    SymbolInfo *getNext(){
        return next;
    }
};
class ScopeTable
{
    SymbolInfo **table;
    int size;
    int id;
    ScopeTable *parentScope;
    public:
    ScopeTable(int size,int id){
        this->size=size;
        this->id=id;
        table=new SymbolInfo*[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        }
        parentScope=NULL;
    }
    void setParentScope(ScopeTable *parentScope){
        this->parentScope=parentScope;
    }
    ScopeTable *getParentScope(){
        return parentScope;
    }
    int hashFunction(string name){
        int sum=0;
        for(int i=0;i<name.length();i++){
            sum=sum+name[i];
        }
        return sum%size;
    }
    bool insert(string name,string type){
        int index=hashFunction(name);
        SymbolInfo *temp=table[index];
        SymbolInfo *newSymbol=new SymbolInfo(name,type);
        if(temp==NULL){
            table[index]=newSymbol;
            cout<<"Inserted in ScopeTable# "<<id<<" at position "<<index<<",0"<<endl;
            return true;
        }
        int pos=1;
        while(temp->getNext()!=NULL){
            if(temp->getName()==name){
                cout<<"<"<<name<<","<<type<<"> already exists in current ScopeTable"<<endl;
                return false;
            }
            temp=temp->getNext();
            pos++;
        }
        if(temp->getName()==name){
            cout<<"<"<<name<<","<<type<<"> already exists in current ScopeTable"<<endl;
            return false;
        }
        temp->setNext(newSymbol);
        cout<<"Inserted in ScopeTable# "<<id<<" at position "<<index<<","<<pos<<endl;
        return true;
    }
    bool deleteSymbol(string name){
        int index=hashFunction(name);
        SymbolInfo *temp=table[index];
        if(temp==NULL){
            cout<<"Not found"<<endl;
            return false;
        }
        if(temp->getName()==name){
            table[index]=temp->getNext();
            cout<<"Deleted entry at "<<index<<",0 from current ScopeTable"<<endl;
            return true;
        }
        int pos=1;
        while(temp->getNext()!=NULL){
            if(temp->getNext()->getName()==name){
                temp->setNext(temp->getNext()->getNext());
                cout<<"Deleted entry at "<<index<<","<<pos;
                return true;
            }
            temp=temp->getNext();
            pos++;
        }
        cout<<"Not found"<<endl;
        return false;
    }
    SymbolInfo *lookUp(string name){
        int index=hashFunction(name);
        SymbolInfo *temp=table[index];
        if(temp==NULL){
            return NULL;
        }
        while(temp!=NULL){
            if(temp->getName()==name){
                return temp;
            }
            temp=temp->getNext();
        }
        return NULL;
    }
    void print(){
        cout<<"ScopeTable # "<<id<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<" --> ";
            SymbolInfo *temp=table[i];
            while(temp!=NULL){
                cout<<"<"<<temp->getName()<<","<<temp->getType()<<"> ";
                temp=temp->getNext();
            }
            cout<<endl;
        }
    }
    ~ScopeTable(){
        for(int i=0;i<size;i++){
            SymbolInfo *temp=table[i];
            while(temp!=NULL){
                SymbolInfo *temp2=temp;
                temp=temp->getNext();
                delete temp2;
            }
        }
        delete []table;
    }
};
int main(){
    int size;
    cout<<"Enter size of ScopeTable: ";
    cin>>size;
    ScopeTable *currentScope=new ScopeTable(size,1);
    int id=1;
    while(true){
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. LookUp"<<endl;
        cout<<"4. Print"<<endl;
        cout<<"5. Enter new Scope"<<endl;
        cout<<"6. Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            string name,type;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter type: ";
            cin>>type;
            currentScope->insert(name,type);
        }
        else if(choice==2){
            string name;
            cout<<"Enter name: ";
            cin>>name;
            currentScope->deleteSymbol(name);
        }
        else if(choice==3){
            string name;
            cout<<"Enter name: ";
            cin>>name;
            SymbolInfo *temp=currentScope->lookUp(name);
            if(temp==NULL){
                cout<<"Not found"<<endl;
            }
            else{
                cout<<"Found in ScopeTable# "<<id<<" at position "<<currentScope->hashFunction(name)<<","<<endl;
            }
        }
        else if(choice==4){
            currentScope->print();
        }
        else if(choice==5){
            id++;
            ScopeTable *newScope=new ScopeTable(size,id);
            newScope->setParentScope(currentScope);
            currentScope=newScope;
            cout<<"New ScopeTable with id "<<id<<" created"<<endl;
        }
        else if(choice==6){
            break;
        }
    }
    return 0;
}