#include <iostream>
using namespace std;
int piobet(int input[], int start, int end)
{
  int count = 0;
  int temp = input[start];
  for (int i = start + 1; i <= end; i++)
  {
    if (temp > input[i])
    {
      count++;
    }
  }
  int pivoetIndex = start + count;
  int ext = input[start];
  input[start] = input[pivoetIndex];
  input[pivoetIndex] = ext;
  int i = start, j = end;
  while (i < pivoetIndex && j > pivoetIndex)
  {
    if (input[i] < input[pivoetIndex])
    {
      i++;
    }
    else if (input[j] >= input[pivoetIndex])
    {
      j--;
    }
    else
    {
      int temp1 = input[i];
      input[i] = input[j];
      input[j] = temp1;
      i++;
      j--;
    }
  }
  return pivoetIndex;
}
void quickSort(int input[], int start, int end) {
  if (start >= end) {
    return;
  }
  int pi = piobet(input, start, end);
  quickSort(input, start, pi-1);
  quickSort(input, pi+1,end);
}
void quickSort(int input[], int size) {
  quickSort(input, 0, size-1);
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}