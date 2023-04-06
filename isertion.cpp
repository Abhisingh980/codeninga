#include <iostream>
using namespace std;
void insertSort(int input[],int size){
    int j;
    for(int i=1;i<size;i++){
        int temp=input[i];
        j=i-1;
        // while(j>=0 && input[j]>temp){
        //     input[j+1]=input[j];
        //     j--;
        // }
        for(;j>=0;j--)
        {
            if(input[j]>temp){
                input[j+1]=input[j];
            }
            else{
                break;
            }
        }
        input[j+1]=temp;
    }
}
int main()
{
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the element "<<i+1<<" : ";
        cin >> input[i];
    }
    insertSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    delete[] input;
}