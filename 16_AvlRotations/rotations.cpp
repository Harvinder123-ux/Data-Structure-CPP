#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    // agar toh node ka left or right null hai toh return 0 kardo else return kardo n->height joki 1 inital mein;
    return n->height;
}

struct node *createNode(int key)
{
    struct node *n = new node;
    n->left = nullptr;
    n->right = nullptr;
    n->key = key;
    n->height = 1;
    return n;
}
// now do the three most important functions
// balance factor - height of left subtree - height or right subtree for each node

// this is the utility function to find the balance factor
int getBalanceFactor(struct node *n)
{
    if (n == nullptr)
    {
        return 0;
    }

    return getHeight(n->left) - getHeight(n->right);
}

// now time for show - rotations

// first left rotate
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    // struct node*T1 = x->left;
    // struct node*T3 = y->right;
    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->right), getHeight(y->right));
    x->height = 1 + max(getHeight(x->right), getHeight(x->right));

    // why return x - kyunki x abhi root node ban chuka h
    return x;
}

// first left rotate
struct node *leftRotation(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    // struct node*T1 = x->left;
    // struct node*T3 = y->right;
    y->left = x;
    x->right = T2;

    y->height = 1+ max(getHeight(y->right), getHeight(y->left));
    x->height = 1+ max(getHeight(x->right), getHeight(x->left));

    // why return y - kyunki y abhi root node ban chuka h
    return y;
}

// struct node *insertBST(struct node *node, int key)
// {
//     struct node *prev;
//     while (node != nullptr)
//     {
//         prev = node;
//         if (key < node->key)
//         {
//             node = node->left;
//         }
//         else if (key > node->key)
//         {
//             node = node->right;
//         }
//         else if (key == node->key)
//         {
//             cout << "node already exist" << endl;
//         }
//         struct node *newNode = createNode(key);
//         if (prev == nullptr)
//         {
//             node = newNode;
//         }
//         if (key < prev->key)
//         {
//             prev = prev->left;
//         }
//         if (key > prev->key)
//         {
//             prev = prev->right;
//         }
//         return newNode;
//     }
// }

int max(int a, int b)
{
    return a > b ? a : b;
}

struct node *insertBSTRecurisve(struct node *node, int key)
{
    if (node == nullptr)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left = insertBSTRecurisve(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertBSTRecurisve(node->right, key);
    } else {
        // Key already exists, handle accordingly (print a message or ignore)
         cout << "node already exist" << endl;
        return node;
    }
    

    node->height = 1 + max(getHeight(node->right), getHeight(node->left));
    int bf = getBalanceFactor(node);

    // now insertion ke baad there is chance it get unbalanced -- for solve this situation we have 4 cases of rotation
    // inko samjne ke liye meri copy mein dry run check kijiye usme ache se nikala hai in condidtions ko
    // left left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotation(node);
    }
    // left right case
    if (bf > 1 && key > node->left->key)
    // left tree mein first imablance  node child ke corrosponding who is in path
    {
        node->left = leftRotation(node->left);
        return rightRotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->key)
    // right tree mein first imablance node ke child ke corrosponding who is in path
    {
        node->right = rightRotate(node->right);
        return leftRotation(node);
    }

    return node;
}

void preOrder(struct node *root)

{
    //for recursive call never use the loops approach while or anything
    if (root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct node *root = nullptr;
    root = insertBSTRecurisve(root, 1);
    root = insertBSTRecurisve(root, 2);
    root = insertBSTRecurisve(root, 4);
    root = insertBSTRecurisve(root, 5);
    root = insertBSTRecurisve(root, 6);
    root = insertBSTRecurisve(root, 3);

    preOrder(root);

    return 0;
}

// struct node *insertBSTRecurisve(struct node *node, int key)
// {
//     if (node == nullptr)
//     {
//         return createNode(key);
//     }

//     if (key < node->key)
//     {
//         node->left = insertBSTRecurisve(node->left, key);
//     }
//     else if (key > node->key)
//     {
//         node->right = insertBSTRecurisve(node->right, key);
//     }
//     else
//     {
//         cout << "node already exists" << endl;
//         return node;
//     }

//     // Update height and calculate balance factor
//     node->height = 1 + max(getHeight(node->right), getHeight(node->left));
//     int bf = getBalanceFactor(node);

//     // Now handle balancing cases
//     // left left case
//     if (bf > 1 && key < node->left->key)
//     {
//         return rightRotate(node);
//     }

//     // right right case
//     if (bf < -1 && key > node->right->key)
//     {
//         return leftRotation(node);
//     }

//     // left right case
//     if (bf > 1 && key > node->left->key)
//     {
//         node->left = leftRotation(node->left);
//         return rightRotate(node);
//     }

//     // right left case
//     if (bf < -1 && key < node->right->key)
//     {
//         node->right = rightRotate(node->right);
//         return leftRotation(node);
//     }

//     return node;
// }
