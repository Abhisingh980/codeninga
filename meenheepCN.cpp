#include <iostream>
#include <vector>
using namespace std;
class meenHeep
{
    vector<int> pq;
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }

public:
    int getmin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int data)
    {
        pq.push_back(data);
        //up heapify 
        int childindex = pq.size() - 1;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[parentindex] < pq[childindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }
    int remove()
    {
        if (pq.size() == 0)
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        //down heapify
        int pi = 0;
        int lci=2*pi+1;
        int rci=2*pi+2;
        while(lci<pq.size()){
            int midp = pi;
            if(pq[midp]<pq[lci]){
                midp=lci;
            }
            if(rci<pq.size() &&pq[midp]<pq[rci]){
                midp=rci;
            }
            if(midp==pi){
                break;
            }
            int temp=pq[midp];
            pq[midp]=pq[pi];
            pq[pi]=temp;

            pi=midp;
            lci = 2 * pi + 1;
            rci = 2 * pi + 2;
        }
        // while (pi <= pq.size() - 1)
        // {

        //    int  lci = (pi * 2) + 1;
        //    int  rci = (pi * 2) + 2;
        //     if (pq[pi] > pq[lci] && pq[lci] < pq[rci])
        //     {
        //         int temp = pq[pi];
        //         pq[pi] = pq[lci];
        //         pq[lci] = temp;
        //         pi = lci;
        //     }
        //     else if (pq[pi] > pq[rci] && pq[lci] > pq[rci])
        //     {
        //         int temp = pq[pi];
        //         pq[pi] = pq[rci];
        //         pq[rci] = temp;
        //         pi = rci;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
       
        return ans;
    }
    void print()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    meenHeep h;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Remove Min" << endl;
        cout << "3. Get Min" << endl;
        cout << "4. Print" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter the element to be inserted: ";
            cin >> element;
            h.insert(element);
            break;
        case 2:
            cout << "the minimum element of heep  : " << h.remove() << endl;
            ;
            break;
        case 3:
            cout << "The minimum element is: " << h.getmin() << endl;
            break;
        case 4:
            h.print();
            break;
        case 5:
            return 0;
        default:
            cout << "Enter a valid choice" << endl;
        }
    }
}
