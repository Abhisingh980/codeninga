#include <iostream>
#include <vector>
using namespace std;
class meenHeep{
    vector<int> pq;
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    void downHeepyfy()
    {
        int i = 0;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        while (left < pq.size())
        {
            int minIndex = i;
            if (pq[minIndex] > pq[left])
            {
                minIndex = left;
            }
            if (right < pq.size() && pq[minIndex] > pq[right])
            {
                minIndex = right;
            }
            if (minIndex == i)
            {
                break;
            }
            int temp = pq[i];
            pq[i] = pq[minIndex];
            pq[minIndex] = temp;
            i = minIndex;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }
    void heepyfy()
    {
        int i = pq.size() - 1;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (pq[i] < pq[parent])
            {
                int temp = pq[i];
                pq[i] = pq[parent];
                pq[parent] = temp;
            }
            else
            {
                break;
            }
            i = parent;
        }
    }

    public:
    meenHeep(){}
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
   
    void insert(int data){
        pq.push_back(data);
        heepyfy();
    }
    
    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        downHeepyfy();
        return ans;
    }
    void print(){
        for(int i = 0; i < pq.size(); i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    meenHeep h;
    while(1){
        cout<<"1. Insert"<<endl;
        cout<<"2. Remove Min"<<endl;
        cout<<"3. Get Min"<<endl;
        cout<<"4. Print"<<endl;
        cout<<"5. Exit"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
       
        switch(choice){
            case 1:
                int element;
                cout<<"Enter the element to be inserted: ";
                cin>>element;
                h.insert(element);
                break;
            case 2:
                cout<<"The minimum element is: "<<h.removeMin()<<endl;
                break;
            case 3:
                cout<<"The minimum element is: "<<h.getMin()<<endl;
                break;
            case 4:
                h.print();
                break;
            case 5:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
        }
    }
}

