//  #include <iostream>
//   using namespace std;
//    int main(){
// // int a=65;
// // int* p=&a;
// // char* pc=(char*)p;
// // cout<<*p<<" " <<*pc<<endl;
// // cout<<*pc+1<<" " <<*pc+2<<endl;
// cout<<((1/2)+(1/4)+(1/8)+(1/16))<<endl;
// return 0; 
// // }
#include <iostream>
//#include "solution.h"
using namespace std;
int extra(char *, int, int);
int strlength(char *);
bool checkPalindrome(char input[])
{
    // Write your code here
    int a = 0;
    int end = strlength(input);
    int b = extra(input, a, end);
    if (b == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int extra(char input[], int strat, int end)
{
    if (input[0] == '\0')
    {
        return 0;
    }
    if(strat == end-1)
    {
        return 1;
    }
    else
    {
        if (input[strat] == input[end - 1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
        extra(input, strat + 1, end - 1);
    }
}
int strlength(char s[])
{
    if (s[0] == '\0')
    {
        return 0;
    }
    else
    {
        int b = strlength(s + 1);
        return 1 + b;
    }
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}