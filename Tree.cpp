#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* TakeInputleevelwise(){
    cout << "enter the data :";
    int rootdata;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
     if(root==NULL){
        return root;
     }
    queue<TreeNode<int>*> que;
    que.push(root);
    while(que.size()!=0){
       TreeNode<int>* front=que.front();
       que.pop();
        cout<<"enter the neumber of cild : "<<front->data<<" : ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int data;
            cout<<"enetr the child data "<<i<<" "<<front->data<<" : ";
            cin>>data;
            TreeNode<int>* child=new TreeNode<int>(data);
            front->children.push_back(child);
            que.push(child);
        }
    }
    return root;
}
TreeNode<int>* TakeInput(){
    cout<<"enter the data :";
    int rootdata;
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    cout<<"Enter the size of cinld :";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child=TakeInput();
         root->children.push_back(child);
    }
    return root;
}
void Print(TreeNode<int>* root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        Print(root->children[i]);
    }
}
int main(){
    TreeNode<int>* root=TakeInputleevelwise();
    Print(root);
    //delete TreeNode;
}