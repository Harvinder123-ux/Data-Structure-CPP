#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorderTraverse(struct node *ptr)
{
    if (ptr != nullptr)
    {
        inorderTraverse(ptr->left);
        cout << ptr->data<< " ";
        inorderTraverse(ptr->right);
    }
}

struct node *createNode(int data)
{
    struct node *n = new node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

int isBST(struct node *root)
{
    struct node *prev = nullptr;
    if (root != nullptr)
    {
       
        if (!isBST(root->left))
        {
            return 0;
        }
        //agar previous node ka data bada hai checking node se toh return condition false
        if (prev != nullptr && root->data <= prev->data)
        {
            return 0;
        }
    
            prev = root;
            return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    // harry bhaiya type
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // our binary tree

    //       5
    //      / \
    //     3   6
    //    / \ 
    //   1   4

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    //    preOrderTraverse(p);

    //    postOrderTraverse(p);

    inorderTraverse(p);
    cout << endl;
    cout << isBST(p);

    return 0;
}