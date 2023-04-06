// #include <iostream>
// using namespace std;
// int main()
// {
//     int numbers[5];
//     int *p;
//     p = numbers;
//     *p = 10;
//     p = &numbers[2];
//     *p = 20;
//     p--;
//     *p = 30;
//     p = numbers + 3;
//     *p = 40;
//     p = numbers;
//     *(p + 4) = 50;
//     for (int n = 0; n < 5; n++)
//     {
//         cout << numbers[n] << ",";
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;

// #define MULTIPLY(a, b) a *b

// int main()
// {
//     cout << MULTIPLY(2 + 3, 3 + 5);
//     return 0;
// }
// #include <iostream>
// using namespace std;

// int main()
// {
//     int const p = 5;
//     cout << ++p;
//     return 0;
// }
#include <iostream>
using namespace std;
// #include "Solution.h"
// void print(int n)
// {
//     // write your code here
//     if (n == 1)
//     {
//         cout << 1 << " ";
//     }
//     else
//     {
//         print(n - 1);
//         cout << n << " ";
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     print(n);
// }
// #include <iostream>
// //#include "Solution.h"
// using namespace std;
// int count(int n)
// {
    // write your code here
//     int i = 0;
//     if (n == 1)
//     {
//         i++;
//         return i;
//     }
//     else
//     {
//         i++;
//         count(n%10);//156
//         cout<<n/10<<endl;
//         return i;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     cout << count(n) << endl;
// }
// #include <iostream>
// using namespace std;

// void print(int n)
// {
//     if (n < 0)
//     {
//         return;
//     }
//     if (n == 0)
//     {
//         cout << n << “ “;
//         return;
//     }
//     print(n--);
//     cout << n << “ “;
// }

// int main()
// {
//     int num = 3;
//     print(num);
// }
#include <iostream>
using namespace std;
int allIndexes(int input[], int size, int x, int output[])
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Save all the indexes in the output array passed and return the size of output array.
       Taking input and printing output is handled automatically.
    */
    int n = 0;
    if (size == 0)
    {
        return 0;
    }
    else
    {

        allIndexes(input, (size - 1), x, output);
        if (input[size - 1] == x)
        {
            n++;
            output[n] = size - 1;
        }
        
        
    }
    return n;
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

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    cout<<size<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;
}