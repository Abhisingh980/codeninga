#include <iostream> 
using namespace std;
int main(){
 int n;
 cout<<"enter the size  :";
 cin>>n;
 int *arr=new int[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 //hashing
 int *hash=new int[1e6];
 //counter
 for(int i=0;i<n;i++){
    hash[arr[i]]++;
 }
 //count in array
 int find;
 cout<<"enter the key : ";
 cin>>find;
 cout<<"the number of count is : "<<hash[find]<<endl;
}