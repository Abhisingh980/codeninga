#include <iostream>
using namespace std;
void display(int count[],int size)
{
    for(int i=0;i<size+1;){
        if(count[i]!=0){
            cout<<i<<" ";
            count[i]--;
        }
        else{
            i++;
        }
    }
}
int maxFinder(int input[],int size){
    //int max=*max_element(input, input + size);//time complexcity is O(n);
     int max=input[0];
     for(int i=1;i<size;i++){
        if(max<input[i]){
            max=input[i];
        }
     }
     return max;
}
void countSort(int input[],int size){
     int max=maxFinder(input,size);
     int * count=new int[max+1];
     for(int i=0;i<=max;i++){
        count[i]=0;
     }
     for(int i=0;i<size;i++){
        int temp=input[i];
        count[temp]++;
     }
     display(count,max);
     delete [] count;
}
int main(){
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> input[i];
    }
    countSort(input, n);
    delete[] input;
}