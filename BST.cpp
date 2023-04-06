#include <iostream>
#define SPACE 6
using namespace std;
class Tree
{
public:
    int data;
    Tree *left, *right;
    Tree()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Tree(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    Tree *root;
    BST()
    {
        root = NULL;
    }
    bool Searching(Tree *, int);
    Tree *Insertion(Tree *, int);
    Tree *Deletion(Tree *, int);
    void PreOrder(Tree *);
    void PostOrder(Tree *);
    void InOrder(Tree *);
    int max(Tree *);
    int min(Tree *);
    void PrintTree(Tree *, int);
    int HightOfTree(Tree *);
    void PrintLeavel(Tree *, int);
    void PrintLabelwise(Tree *);
    Tree *successor(Tree *);
    Tree *Predessor(Tree *);
};
Tree *BST::successor(Tree *root)
{
    Tree *temp = root;
    // gives you min value node or left Most Node
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Tree *BST::Predessor(Tree *root){
    Tree *temp=root;
    // gives you max value node or right Most Node
    while (temp->right==NULL){
        temp=temp->right;
    }
    return temp;
}
bool BST::Searching(Tree *root, int value)
{
    if (root == NULL)
    {
        cout << "The value is not found : " << endl;
        return false;
    }
    else if (root->data == value)
    {
        cout << "The value is found : " << endl;
        return true;
    }
    else if (root->data > value)
    {
        Searching(root->left, value);
    }
    else
    {
        Searching(root->right, value);
    }
    return false;
}
Tree *BST::Insertion(Tree *NewNode, int value)
{
    if (root == NULL)
    {
        NewNode->data = value;
        root = NewNode;
        cout << "dta insterted root Succesfully - " << endl;
        return NewNode;
    }
    else if (NewNode->data == value)
    {
        cout << "  -  Duplicate data is Not Allowed - " << endl;
        return NewNode;
    }
    else if (NewNode->data > value)
    {
        if (NewNode->left == NULL)
        {
            Tree *Node = new Tree(value);
            NewNode->left = Node;
            cout << "dta insterted left Succesfully - " << endl;
            return NewNode;
        }
        else
        {
            Insertion(NewNode->left, value);
        }
    }
    else
    {
        if (NewNode->right == NULL)
        {
            Tree *Node = new Tree(value);
            NewNode->right = Node;
            cout << "dta insterted right Succesfully - " << endl;
            return NewNode;
        }
        else
        {
            Insertion(NewNode->right, value);
        }
    }
    return NewNode;
}
Tree *BST::Deletion(Tree *root, int value)
{
    if (root == NULL)
    {
        cout << "Empty Tree - " << endl;
        return NULL;
    }
    else if (value < root->data)
    {
        Deletion(root->left, value);
    }
    else if (value > root->data)
    {
        Deletion(root->right, value);
    }
    else
    {
        //singel child or No child deletion 
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            //double child deletion
            Tree *temp = successor(root->right);
            root->data = temp->data;
            Deletion(root->right, temp->data);
            return temp;
        }
    }
    return root;
}
void BST::PreOrder(Tree *root)
{
    Tree *temp = root;
    cout << temp->data << " ";
    if (temp->left != NULL)
    {
        PreOrder(temp->left);
    }
    if (temp->right != NULL)
    {
        PreOrder(temp->right);
    }
}
void BST::PostOrder(Tree *root)
{
    Tree *temp = root;
    if (temp->right != NULL)
    {
        PostOrder(temp->right);
    }
    if (temp->left != NULL)
    {
        PostOrder(temp->left);
    }
    cout << temp->data << " ";
}
void BST::InOrder(Tree *root)
{
    Tree *temp = root;
    if (temp->left != NULL)
    {
        InOrder(temp->left);
    }
    cout << temp->data << " ";
    if (temp->right != NULL)
    {
        InOrder(temp->right);
    }
}
int BST::max(Tree *root)
{
    if (root == NULL)
        return -1;
    else if (root->right == NULL)
        return root->data;
    else
        return max(root->right);
}
int BST::min(Tree *root)
{
    if (root == NULL)
        return -1;
    else if (root->left == NULL)
        return root->data;
    else
        return min(root->left);
}
int BST::HightOfTree(Tree *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int lhight = HightOfTree(root->left);
        int rhight = HightOfTree(root->right);
        if (lhight > rhight)
        {
            return (lhight + 1);
        }
        else
        {
            return (rhight + 1);
        }
    }
}
void BST::PrintLeavel(Tree *root, int leavel)
{
    if (root == NULL)
    {
        return;
    }
    else if (leavel == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        PrintLeavel(root->left, leavel - 1);
        PrintLeavel(root->right, leavel - 1);
    }
}
void BST::PrintLabelwise(Tree *root)
{
    int h = HightOfTree(root);
    for (int i = 0; i <= h; i++)
        PrintLeavel(root, i);
}
void BST::PrintTree(Tree *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += SPACE;
    PrintTree(root->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    PrintTree(root->left, space);
}
int main()
{
    Tree *rootNode = new Tree;
    BST b;
    int leavel;
    while (1)
    {
        cout << "1. Insertion" << endl;
        cout << "2. Searching" << endl;
        cout << "3. Deletion" << endl;
        cout << "4. PreOrder" << endl;
        cout << "5. PostOrder" << endl;
        cout << "6. InOrder" << endl;
        cout << "7. Maximum" << endl;
        cout << "8. Minimum" << endl;
        cout << "9. HIGHT" << endl;
        cout << "10. print-Give-Leavel" << endl;
        cout << "11. print-lavel-Wise" << endl;
        cout << "12. Print Tree " << endl;
        cout << "13.exit " << endl;
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;
        system("clear");
        switch (choice)
        {
        case 1:
            int n;
            cout << "Enter the value : ";
            cin >> n;
            rootNode = b.Insertion(rootNode, n);
            break;
        case 2:
            int n1;
            cout << "Enter the value : ";
            cin >> n1;
            b.Searching(rootNode, n1);
            break;
        case 3:
            int n2;
            cout << "Enter the value : ";
            cin >> n2;
            rootNode = b.Deletion(rootNode, n2);
            break;
        case 4:
            b.PreOrder(rootNode);
            cout << endl;
            break;
        case 5:
            b.PostOrder(rootNode);
            cout << endl;
            break;
        case 6:
            b.InOrder(rootNode);
            cout << endl;
            break;
        case 7:
            cout << "Maximum value is : " << b.max(rootNode) << endl;
            break;
        case 8:
            cout << "Minimum value is : " << b.min(rootNode) << endl;
            break;
        case 9:
            cout << "        -----   " << b.HightOfTree(rootNode);
            cout << endl;
            break;
        case 10:
            leavel = b.HightOfTree(rootNode);
            cout << "enter the Leavel less than : " << leavel << " : ";
            cin >> leavel;
            b.PrintLeavel(rootNode, leavel);
            cout << endl;
            break;
        case 11:
            b.PrintLabelwise(rootNode);
            cout << endl;
            break;
        case 12:
            b.PrintTree(rootNode, 2);
            cout << endl;
            break;
        case 13:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}