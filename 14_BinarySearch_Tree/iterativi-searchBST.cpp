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

int isBST(struct node *root)
{
    struct node *prev = nullptr;
    if (root != nullptr)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != nullptr && root->data <= prev->data)
        {
            return 0;
        }
        else
        {
            prev = root;
            return isBST(root->right);
        }
    }
    else
    {
        return 1;
    }
}

struct node *searchIter(struct node *root, int key)
{
    while (root != nullptr)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
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

    // p->left = p1;
    // p->right = p2;

    // p1->left = p3;
    // p1->right = p4;

    //    preOrderTraverse(p);

    //    postOrderTraverse(p);

    // inorderTraverse(p);
    // cout << endl;
    // cout << isBST(p)<<endl;

    // searchBST(p, 75);

    // // cout<<"the search of BSt"<<key ;

    // Displaying the inorder traversal of the binary tree
    cout << "Inorder Traversal: ";
    inorderTraverse(p);
    cout << endl;

    // Checking if the tree is a BST
    cout << "Is BST: " << isBST(p) << endl;

    // Searching for a key in the BST
    int keyToSearch = 105;
    struct node *result = searchIter(p, keyToSearch);

    if (result != nullptr)
    {
        cout << "Key " << keyToSearch << " found in the BST at node with data: " << result->data << endl;
    }
    else
    {
        cout << "Key " << keyToSearch << " not found in the BST." << endl;
    }

    return 0;
}
