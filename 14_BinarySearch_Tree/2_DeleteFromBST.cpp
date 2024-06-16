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
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return nullptr;
}

// void insertBST (struct node*root, int key){
//     struct node*prev = nullptr;
//     while (root != nullptr)
//     {
//         prev = root;
//         if (key == root->data){
//             cout<<"can't insert! node already exist"<<endl;
//         }
//         else if (key <root->data){
//             root = root ->left;
//         }else {
//             root = root->right;
//         }
//     }
//     struct node*newNode = createNode(key);
//     if(key<prev->data){
//         prev->left = newNode;
//     }else {
//         prev->right = newNode;
//     }

// }

int findMinInRightSubtree(struct node *root)
{
    // The minimum value in a BST is always in the leftmost node.
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

int findMaxInLeftSubtree(struct node *root)
{
    // The maximum value in a BST is always in the rightmost node.
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}

struct node *inOrderPredecessor(struct node *root)
{ // isme - already maalum hai ki hamara predecessor left mein hoga toh root ko root ke left mein place kardenge
    root = root->left;
    //         50
    //         /   \
    //    (40)    60
    //      / \     / \
    //   (20)   45  55 70
    while (root->right != nullptr)
    {
        root = root->right;
        // i have to watch that video then i will solve properly this one too
    }
    return root;
    //
}

struct node *deleteFromBST(struct node *root, int value)
{
    struct node *Ipre;
    // base condition - ki aagar tree hoga hi empty toh return empty
    if (root == nullptr)
    {
        return nullptr;
    }

    // isme - agar hamari di gyi node value chhoti hogi tree ke root->data se toh hamara function call karega root->left mein
    if (value < root->data)
    {
        root->left = deleteFromBST(root->left, value);
        return root;
    }
    // isme - same agar value badi hui root ke data se function call karega root->right mein
    else if (value > root->data)
    {
        root->right = deleteFromBST(root->right, value);
        return root;
    }

    //deletion strategy
    if (root->data == value)
    {

        // 0 - child condition
        // isme - agar root ka left and right == nullptr honge means aap leafnode par ho! toh delete kardo
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1 child case
        //subtree or node ka left child hai
        if (root->left != nullptr && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // subtree or node right child hai
        if (root->left == nullptr && root->right != nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child case nobody is null
        if (root->left != nullptr && root->right != nullptr)
        {
            int mini = findMinInRightSubtree(root->right);//minimum value
            root->data = mini;//copy the valuein which node we want to delete for replace
            root->right = deleteFromBST(root->right, mini);//yaha se copy kya h usme khali node ko delete kardo
            return root;//return kardo root ko as right subtree min val min
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
    deleteFromBST(p, 50);
    cout << "the root data!" << p->data << endl;
    inorderTraverse(p);

    return 0;
}