#include <iostream>
using namespace std;
void mergeSort(int input[], int size)
{
    // Write your code here
    if (size == 1)
    {
        return;
    }
    int mid = size / 2;
    int *left = new int[mid];
    int *right = new int[size - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = input[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = input[i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    int i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid)
    {
        if (left[i] < right[j])
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
    while (i < mid)
    {
        input[k] = left[i];
        i++;
        k++;
    }
    while (j < size - mid)
    {
        input[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}
void binarySearch(int input[], int start, int end, int element)
{
    int mid;
    mid = (start + end )/ 2;
    if (end == start)
    {
        return;
    }
    else if (input[mid] == element)
    {
        cout << input[mid] << endl;
        cout << mid + 1 << endl;
    }
    else if(input[start]==element){
        cout << input[start] << endl;
        cout << start + 1 << endl;
    }
    else if(input[end]==element){
        cout << input[end] << endl;
        cout << end + 1 << endl;
    }
    else if (input[mid] > element)
    {
        binarySearch(input, start+1, mid - 1, element);
    }
    else
    {
        binarySearch(input, mid + 1, end-1, element);
    }
}
int main()
{
    //element must be therer
    cout << "Enter the size of array : ";
    int n, start;
    start = 0;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "the number is " << i + 1 << " : ";
        cin >> input[i];
    }
    int element;
    cout << " Enter the element which you want to find : ";
    cin >> element;
    mergeSort(input,n);
    binarySearch(input, start, n, element);
    delete[] input;
}