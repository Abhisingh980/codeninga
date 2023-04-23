#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;
void printdepth(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    printdepth(root->left, k - 1);
    printdepth(root->right, k - 1);
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    queue<int> R;
    R.push(0);
    q.push(root);
  if(root->data==node){
    while(!q.empty()){
        int k1=R.front();
        R.pop();
        if(k1==1){
            printdepth(q.front()->left,k-q.size()-1);
        }
        if(k1==2){
            printdepth(q.front()->right,k-q.size()-1);
        }
        if(k1==0&&R.front()==1){
            printdepth(q.front()->right,k-q.size()-1);
        }
        if(k1==0&&R.front()==2){
            printdepth(q.front()->left,k-q.size()-1);
        }
        q.pop();
    }
    return;
      
  }
    if(root->left!=NULL){
            q.push(q.front()->left);
            R.push(1);
    }
    if(root->right!=NULL){
            q.push(q.front()->right);
            R.push(2);
    }
    nodesAtDistanceK(root->left,node,k);
    nodesAtDistanceK(root->right,node,k);

}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}