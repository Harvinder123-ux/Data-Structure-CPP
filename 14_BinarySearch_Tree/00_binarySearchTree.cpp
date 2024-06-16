#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// void preOrderTraverse (struct node*root){

//     if (root != nullptr){
//         cout<<root->data<<" ";
//         preOrderTraverse(root->left);
//         preOrderTraverse(root->right);
//     }

// }

// void postOrderTraverse (struct node*root){

//     if (root != nullptr){
//         postOrderTraverse(root->left);
//         postOrderTraverse(root->right);
//         cout<<root->data<<" ";

//     }

// }

void inorderTraverse(struct node *root)
{

    if (root != nullptr)
    {
        inorderTraverse(root->left);
        cout << root->data << " ";
        inorderTraverse(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = nullptr;

    if (root != nullptr)
    {
        // Recursive call to check the left subtree
        if (!isBST(root->left))
        {
            return 0;
        }
        // Check if the current node's data is greater than the previous node's data
        if (prev != nullptr && root->data <= prev->data)
        {
            return 0;
        }
        // Update prev to the current node
        prev = root;
        // Recursive call to check the right subtree
        return isBST(root->right);
    }
    else
    {
        // Base case: If the node is nullptr, return 1 (true)
        return 1;
    }
}

struct node *createNode(int data)
{
    struct node *n = new node; // creating a new node pointer with allocating memory in heap
    n->data = data;            // setting data
    n->left = nullptr;         // setting the left - null
    n->right = nullptr;        // setting the right - null
    return n;                  // return the node
}

int main()
{
    //   //constructing the root node
    //   struct node*p = new node;
    //   p->data = 7;
    //   p->left = nullptr;
    //   p->right = nullptr;

    //  //constructing the first node
    //   struct node*p1 = new node;
    //   p1->data = 2;
    //   p1->left = nullptr;
    //   p1->right = nullptr;

    //   //constructing the second node
    //   struct node*p2 = new node;\
//   p2->data = 3;
    //   p2->left = nullptr;
    //   p2->right = nullptr;

    //   //linking the root node with left and right children (first and second node)
    //   p->left = p1;
    //   p->right = p2;

    // constructing the root node using function - recommended
    //   struct node*p = createNode(4);
    //   struct node*p1 = createNode(1);
    //   struct node*p2 = createNode(5);
    //   struct node*p3 = createNode(2);
    //   struct node*p4 = createNode(6);

    //    p->left = p1;
    //    p->right = p4;

    //    p1->left = p2;
    //    p1->right = p3;

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