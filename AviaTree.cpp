#include <iostream>
#define SPACE 6
using namespace std;
class Node
{
public:
    int data;
    int hight;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        hight = 0;
        left = NULL;
        right = NULL;
    }
    Node(int Hight, int value)
    {
        data = value;
        hight = Hight;
        left = NULL;
        right = NULL;
    }
};
class BalanceTree
{
public:
    Node *root;
    BalanceTree()
    {
        root = NULL;
    }
    Node* Insert(Node *, Node *);
    Node* Delete(Node *, int);
    int Height(Node *);
    int BalanceFactor(Node *);
    Node* rightRotate(Node *);
    Node* leftRotate(Node *);
    Node* search(Node *, int);
    void print(Node *);
    void print2d(Node *, int);
    Node* minValueNode(Node *);
};
int BalanceTree::Height(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        return -1;
    }
    int lheight = Height(temp->left);
    int rheight = Height(temp->right);

    /* use the larger one */
    if (lheight > rheight)
        return (lheight + 1);
    else
        return (rheight + 1);
}
int BalanceTree::BalanceFactor(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return -1;
    }
    return Height(temp->left) - Height(temp->right);
}
Node *BalanceTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->hight = max(Height(y->left), Height(y->right)) + 1;
    x->hight = max(Height(x->left), Height(x->right)) + 1;

    // Return new root
    return x;
}
Node *BalanceTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->hight = max(Height(x->left), Height(x->right)) + 1;
    y->hight = max(Height(y->left), Height(y->right)) + 1;

    // Return new root
    return y;
}
Node *BalanceTree::Insert(Node *r, Node *newNode)

{
    if (r == NULL)
    {
        r = newNode;
        cout << "Insert data succesfully :" << endl;
        return newNode;
    }
    else if (newNode->data < r->data)
    {
        r->left = Insert(r->left, newNode);
    }
    else if (newNode->data > r->data)
    {
        r->right = Insert(r->right, newNode);
    }
    else
    {
        cout << "Data already exist" << endl;
        return newNode;
    }
    int bf = BalanceFactor(r);
    // Left Left Case
    if (bf > 1 && newNode->data < r->left->data)
        return rightRotate(r);

    // Right Right Case
    if (bf < -1 && newNode->data > r->right->data)
        return leftRotate(r);

    // Left Right Case
    if (bf > 1 && newNode->data > r->left->data)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    // Right Left Case
    if (bf < -1 && newNode->data < r->right->data)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;
}
Node *BalanceTree::minValueNode(Node *node)
{
    Node *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
Node *BalanceTree::Delete(Node *head, int value)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Empty Tree - " << endl;
        return head;
    }
    else if (value < temp->data)
    {
       temp->left=Delete(temp->left, value);
    }
    else if (value > temp->data)
    {
       temp->right=Delete(temp->right, value);
    }
    else
    {
        // singel child or No child deletion
        if (temp->left == NULL)
        {
            Node *te = temp->right;
            delete head;
            return te;
        }
        else if (temp->right == NULL)
        {
            Node *te = temp->left;
            delete head;
            return te;
        }
        else
        {
            // double child deletion
            Node *te = minValueNode(temp->right);
            temp->data = te->data;
            Delete(temp->right, te->data);
        }
    }
    int bf = BalanceFactor(head);
    // Left Left Imbalance/case or right rotation
    if (bf == 2 && BalanceFactor(head->left) >= 0)
        return rightRotate(head);

    // left Right Imbalance/case or left-right rotation
    else if (bf ==2 && BalanceFactor(head->left) ==-1){
       head->left=leftRotate(head->left);
        return rightRotate(head);
    }
    //  right Right Imbalance/case or left rotation
    else if (bf ==-2  && BalanceFactor(head->right) <= 0)
        return leftRotate(head);

    // Right Left Imbalance/case or right-left rotation
    else if (bf ==-2 && BalanceFactor(head->right) ==1){
       head->right=rightRotate(head->right);
        return leftRotate(head);
    }
    /* return the (unchanged) node pointer */
    return head;
}
Node* BalanceTree::search(Node *head, int key)
{
    Node* temp = head;
    if(temp==NULL||temp->data==key){
     return temp;
    }
    else if (temp->data > key)
    {
        return search(temp->left, key);
    }
    else
    {
        return search(temp->right, key);
    }
}
void BalanceTree::print(Node *head)
{
    Node *temp = head;
    if (temp->left != NULL)
    {
        print(temp->left);
    }
    cout << temp->data << " ";
    if (temp->right != NULL)
    {
        print(temp->right);
    }
}
void BalanceTree::print2d(Node *r, int space)
{
    if (r == NULL) // Base case  1
        return;
    space += SPACE;           // Increase distance between levels   2
    print2d(r->right, space); // Process right child first 3
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5
        cout << " ";                    // 5.1
    cout << r->data << "\n";            // 6
    print2d(r->left, space);            // Process left child  7
}
int main()
{
    BalanceTree obj;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Print" << endl;
        cout << "5. print2d" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout<<" Enter the choice -- ";
        cin >> choice;
        system ("clear");
        Node *link = new Node();
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter the value to insert : ";
            cin >> value;
            link->data = value;
            obj.root = obj.Insert(obj.root, link);
            break;
        case 2:
            int value1;
            cout << "Enter the value to delete : ";
            cin >> value1;
            obj.root = obj.Delete(obj.root, value1);
            break;
        case 3:
            int value2;
            cout << "Enter the value to search" << endl;
            cin >> value;
            link = obj.search(obj.root, value);
            if (link != NULL)
            {
                cout << "value is found : " << endl;
            }
            else
                cout << "value is not found : " << endl;
            break;
        case 4:
            obj.print(obj.root);
            cout << endl;
            break;
        case 5:
            obj.print2d(obj.root, 3);
            cout << endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}