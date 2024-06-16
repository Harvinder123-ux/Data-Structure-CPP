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
    struct node *n = new node;
    n->right = nullptr;
    n->left = nullptr;
    n->data = key;
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

struct node *predicessor(struct node *root)
//yehh hume root ke predecessor nikal k dega
{   
    root = root->left;
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *Ipre;
    // base condition
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }
    //condition k agar di gyi value chhoti hai toh left mein jayo else if badi hai toh right mein jayo
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
        return root;
    }

    // deleting strategy --- agar value == root data hai toh aisa kro ki predicessor se left ka maximum rightmost element layo aour usse root ke saath copy kar do
    //frr baad mein uss root ko delete kardo
    else 
    {
        Ipre = predicessor(root);
        root->data = Ipre->data;
        root->left = deleteNode(root->left, Ipre->data);
    }
    return root;
}

int main()
{

    // struct node *p = createNode(50);
    // struct node *p1 = createNode(40);
    // struct node *p2 = createNode(60);
    // struct node *p3 = createNode(20);
    // struct node *p4 = createNode(45);
    // struct node *p5 = createNode(55);
    // struct node *p6 = createNode(75);

    // p->left = p1;
    // p->right = p2;

    // p1->left = p3;
    // p1->right = p4;

    // p2->left = p5;
    // p2->right = p6;

    struct node *p = createNode(4);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(3);
    struct node *p4 = createNode(1);

    // our binary tree

    //       4
    //      / \
    //     2   6
    //    / \ 
    //   1   3

    p->left = p1;
    p->right = p2;

    p1->left = p4;
    p1->right = p3;

    inorderTraverse(p);
    cout << endl;
    deleteNode(p, 4);
    cout << "the root data!" << p->data << endl;
    inorderTraverse(p);

    return 0;
}