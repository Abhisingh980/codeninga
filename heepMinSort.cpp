
#include <iostream>
using namespace std;
class HeapSort
{
public:
    int *arr;
    int size;
    int length;
    HeapSort(int A[], int n)
    {
        arr = A;
        size = n;
        length = n;
    }
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            heapify(smallest);
        }
    }
    void buildHeap()
    {
        int i = (length - 1) / 2;
        while (i >= 0)
        {
            heapify(i);
            i--;
        }
    }
    void sort()
    {
        buildHeap();
        for (int i = length - 1; i > 0; i--)
        {
            swap(&arr[0], &arr[i]);
            size--;
            heapify(0);
        }
    }
 void printArray()
    {
        for (int i = 0; i < length; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    HeapSort hs(A, n);
    hs.sort();
    cout << "Sorted array is \n";
    hs.printArray();
    return 0;
}