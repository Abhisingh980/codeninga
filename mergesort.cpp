#include <iostream>
// #include "solution.h"
using namespace std;
void mergeSort(int input[], int size)
{
    // Write your code here
    if(size==1)
    {
        return;
    }
    int mid = size/2;
    int *left = new int[mid];
    int *right = new int[size-mid];
    for(int i=0;i<mid;i++)
    { 
        left[i] = input[i];
    }
    for(int i=mid;i<size;i++)
    {
        right[i-mid] = input[i];
    }
    mergeSort(left,mid);
    mergeSort(right,size-mid);
    int i=0,j=0,k=0;
    while(i<mid && j<size-mid)
    {
        if(left[i]<right[j])
        {
            input[k] = left[i];
            i++;
            k++;
        }
        else
        {
            input[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<mid)
    {
        input[k] = left[i];
        i++;
        k++;
    }
    while(j<size-mid)
    {
        input[k] = right[j];
        j++;
        k++;
    }
    delete [] left;
    delete [] right;
}

int main()
{
    int length;
    cout<<"Enter the length of the array: ";
    cin >> length;
    int *input = new int[length];
    
    for (int i = 0; i < length; i++){
        cout << "Enter the element: " << i + 1 << " : " ;
        cin >> input[i];
       
    }
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout<<"The merge sorted array is : ";
        cout << input[i] << " ";
    }
}