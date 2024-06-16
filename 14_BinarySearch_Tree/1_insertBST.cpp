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
    struct node *p = new node;
    p->data = data;
    p->left = nullptr;
    p->right = nullptr;
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

// struct node *insertBSTRecurisve(struct node *node, int data)
// {
//     if (node == nullptr)
//     {
//         createNode(data);
//     }
//     else if (data < node->data)
//     {
//         node->left = insertBSTRecurisve(node->left, data);
//     }
//     else if (data > node->data)
//     {
//         node->right = insertBSTRecurisve(node->right, data);
//     }
//     else
//     {
//         cout << "node already exist" << endl;
//         return node;
//     }
//     return node;
// }

struct node *searchIter(struct node *root, int data)
{
    while (root != nullptr)
    {
        if (data == root->data)
        {
            return root;
        }
        else if (data < root->data)
        {
            // isme haum kahenge jo root pehle root ko point kar raha tha woh abb left subtree k root ko point karega - 40
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return nullptr;
}
void insertBST(struct node *root, int data)
{
    struct node *prev = nullptr;

    while (root != nullptr)
    { // yeh prev pointer pichli value ko hold kar raha hai next ke update se pehle, hence its previous ptr
        prev = root;
        if (data == root->data)
        {
            cout << "Sorry can't insert! Already Exist" << endl;
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
        // The tree is empty, set the new node as the root
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
    insertBST(p, 60);
    inorderTraverse(p);
    cout << endl;
    cout << p->left->left->left->data;

    return 0;
}
