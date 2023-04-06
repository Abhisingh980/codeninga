#include <iostream>
using namespace std;
void display(int input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
}
int maxFinder(int input[], int size)
{
    // int max=*max_element(input, input + size);//time complexcity is O(n);
    int max = input[0];
    for (int i = 1; i < size; i++)
    {
        if (max < input[i])
        {
            max = input[i];
        }
    }
    return max;
}
void countSort(int input[], int size, int n)
{
    int *count = new int[10];
    int *output = new int[size];
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        int temp = ((input[i] / n) % 10);
        count[temp]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = size-1; i>=0; i--)
    {
        output[count[((input[i] / n) % 10)] - 1] = input[i];
        int temp = ((input[i] / n) % 10);
        count[temp]--;
    }
    for (int i = 0; i < size; i++)
    {
        input[i] = output[i];
    }
    delete[] output;
    delete[] count;
}
void RadixSort(int input[], int size)
{
    int max = maxFinder(input, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(input, size, exp);
    display(input, size);
}
int main()
{
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> input[i];
    }
    RadixSort(input, n);
    delete[] input;
}