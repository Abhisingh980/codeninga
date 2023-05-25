#include <iostream>
using namespace std;
//sort the book class array by id
class Book{
    public:
    int id;
    string name;
    Book(){}
    Book(int id,string name){
        this->id=id;
        this->name=name;
    }
    void bookMearge(Book *b,int start,int end){
        int mid=(start+end)/2;
        int i=start;
        int j=mid+1;
        int k=0;
        Book *temp=new Book[end-start+1];
        while(i<=mid && j<=end){
            if(b[i].id<b[j].id){
                temp[k]=b[i];
                i++;
                k++;
            }
            else{
                temp[k]=b[j];
                j++;
                k++;
            }
        }
        while(i<=mid){
            temp[k]=b[i];
            i++;
            k++;
        }
        while(j<=end){
            temp[k]=b[j];
            j++;
            k++;
        }
        int m=0;
        for(int i=start;i<=end;i++){
            b[i]=temp[m];
            m++;
        }
    }
    void bookMeargesort(Book *b,int start,int end){
        if(start>=end){
            return;
        }
        int mid=(start+end)/2;
        bookMeargesort(b,start,mid);
        bookMeargesort(b,mid+1,end);
        bookMearge(b,start,end);
    }

};
int main(){
    int n;
    cout<<" enter the size of the book"<<endl;
    cin>>n;
    Book *b=new Book[n];
    for(int i=0;i<n;i++){
        cout<<"enter the id and name of the book"<<endl;
        cin>>b[i].id>>b[i].name;
    }
    Book b1;
    b1.bookMeargesort(b,0,n-1);
    for(int i=0;i<n;i++){
        cout<<b[i].id<<" "<<b[i].name<<endl;
    }
}