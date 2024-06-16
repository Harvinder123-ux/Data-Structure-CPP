#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createNode(int key)
{
    struct node *p = new node;
    p->left = nullptr;
    p->right = nullptr;
    p->data = key;

    return p;
}

void inorderTraverse(struct node *root)
{
    if (root != nullptr)
    {
        inorderTraverse(root->left);
        cout << root->data << " ";
        inorderTraverse(root->right);
    }
}

int findMinValRST(struct node *root)
{
   
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

int findMaxValLST(struct node *root)
{
 
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}

struct node *deleteNode(struct node *root, int value)
{
    // base conditon
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
        return root;
    }
    if (value == root->data)
    {
        if (root->left != nullptr && root->right == nullptr)
        {
            /* code */
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            /* code */
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != nullptr && root->right != nullptr)
        {
            int mini = findMinValRST(root->right);
            root->data = mini;/
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
     return root;
}


int main()
{

    struct node *p = createNode(50);
    struct node *p1 = createNode(40);
    struct node *p2 = createNode(60);
    struct node *p3 = createNode(20);
    struct node *p4 = createNode(45);
    struct node *p5 = createNode(55);
    struct node *p6 = createNode(75);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    // inorderTraverse(p);
    // cout<<endl;

    // int keyToSearch = 105;
    // struct node *result = searchIter (p, keyToSearch);

    // if (result != nullptr)
    // {
    //     cout << "Key " << keyToSearch << " found in the BST at node with data: " << result->data << endl;
    // }
    // else
    // {
    //     cout << "Key " << keyToSearch << " not found in the BST." << endl;
    // }

    // insertBST(p, 17);
    // inorderTraverse(p);
    // cout<<endl;
    // cout<<p->left->left->left->data;

    inorderTraverse(p);
    cout << endl;
    deleteNode(p, 50);
    cout << "the root data!" << p->data << endl;
    inorderTraverse(p);

    return 0;
}