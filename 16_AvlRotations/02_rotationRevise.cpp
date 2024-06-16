#include <iostream>
using namespace std;

// Node structure for the AVL tree
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// Function to create a new node with a given key
struct node *createNode(int key)
{
    struct node *n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 1; // Initialize height to 1 for a new node
    return n;
}

// Function to get the height of a node
int getHeight(struct node *root)
{
    if (root == nullptr)
    {
        return 0; // Height of a null node is 0
    }
    return root->height;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(struct node *root)
{
    if (root == nullptr)
    {
        return 0; // Balance factor of a null node is 0
    }
    return getHeight(root->left) - getHeight(root->right);
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return a > b ? a : b;
}

// Function for left rotation
struct node *leftRotation(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform the rotation
    y->left = x;
    x->right = T2;

    // Update heights after rotation
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return y; // Return the new root after rotation
}

// Function for right rotation
struct node *rightRotation(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform the rotation
    x->right = y;
    y->left = T2;

    // Update heights after rotation
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x; // Return the new root after rotation
}

// Function to insert a key into the AVL tree
struct node *insertBST(struct node *node, int key)
{
    if (node == nullptr)
    {
        return createNode(key); // Create a new node for the key
    }
    else if (key < node->key)
    {
        node->left = insertBST(node->left, key); // Recur for the left subtree
    }
    else if (key > node->key)
    {
        node->right = insertBST(node->right, key); // Recur for the right subtree
    }
    else
    {
        cout << "The node already exists" << endl;
        return node; // Key already exists, no change
    }

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node); // Get the balance factor

    // Check for unbalance and perform rotations if necessary

    // Left Left Case: Right Rotation
    if (bf > 1 && key < node->left->key)
    {
        return rightRotation(node);
    }

    // Right Right Case: Left Rotation
    if (bf < -1 && key > node->right->key)
    {
        return leftRotation(node);
    }

    // Left Right Case: Left Rotation on left child followed by Right Rotation on current node
    //child of first imbalance node ke with respect left rotation
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    // Right Left Case: Right Rotation on right child followed by Left Rotation on current node
     //child of first imbalance node ke with respect right rotation
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node; // Return the updated root of the subtree
}

// Function to perform pre-order traversal and print the nodes
void preOrder(struct node *root)
{
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

    // Insert keys into the AVL tree
    root = insertBST(root, 1);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 5);
    root = insertBST(root, 6);
    root = insertBST(root, 3);

    // Perform pre-order traversal to display the tree
    preOrder(root);

    return 0;
}
