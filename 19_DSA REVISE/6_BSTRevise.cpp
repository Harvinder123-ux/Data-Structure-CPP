#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createNode(int data)
{
    struct node *n = new node;
    n->data = data;
    n->right = nullptr;
    n->left = nullptr;
    return n;
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

// int isBST(struct node *root)
// {
//     struct node *prev = nullptr;
//     if (root != nullptr)
//     {
//         if (!isBST(root->left))
//         {
//             return 0;
//         }
//         if (prev != nullptr && root->data <= prev->data)
//         {
//             return 0;
//         }
//         prev = root;
//         return isBST(root->right);
//     }

//     return 1;
// }

void insertBST(struct node *root, int data)
{    
    struct node *prev = nullptr;
    while (root != nullptr)
    {    
        prev = root;
        if (data == root->data)
        {
            cout <<"can't insert node already exist"<<endl;
            return;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
    struct node *newNode = createNode(data);
    if (prev == nullptr)
    {
        root = newNode;
    }
    if (data < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
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

    // our binary tree in this

    //           50
    //         /   \
    //       40     60
    //      / \     / \
    //    20   45  55 70
    //    /
    //   17
    // inorderTraverse(p);
    // // cout << endl;

    insertBST(p, 17);
    // cout<<(p->left->left);
    inorderTraverse(p);
    cout << endl;
   // insertBST(p, 60);
    inorderTraverse(p);
    cout << endl;
    cout << p->left->left->left->data;

    return 0;
}