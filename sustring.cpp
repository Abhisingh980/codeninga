#include <iostream>
#include <math.h>
using namespace std;
int substring(string input, string output[])
{
    if(input.length()==0){
        output[0]=' ';
        return 1;
    }
    else{
        string smallSubString=input.substr(1);
        int smallOutputSize=substring(smallSubString,output);
        for(int i=0;i<smallOutputSize;i++){
            output[i+smallOutputSize]=input[0]+output[i];
        }
        return 2*smallOutputSize;
    }
}
int main(){
    string input;
    cin>>input;
    int n=input.length();
    int x=pow(2,n);
    string* output=new string[x];
    int size=substring(input,output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }
    delete [] output;

}