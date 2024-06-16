#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*right;
    struct node*left;
};

struct node*createNode (int key){
    struct node*p = new node;
    p->left = nullptr;
    p->right = nullptr;
    p->data = key;

    return p;
}

void inorderTraverse (struct node*root){
    if (root != nullptr)
    {
       inorderTraverse(root->left);
       cout<<root->data<< " ";
       inorderTraverse(root->right);
    }
    
}

struct node* searchIter (struct node*root, int key){
    while (root != nullptr)
    {
       if(key == root->data){
        return root;
       }
       else if (key< root->data){
        root = root->left;
       } else {
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

struct node*inPredecessor(struct node* root){
    root = root->left;
   if(root == nullptr){
    return nullptr;
   }
   //check my notes or conclusion page if you don't understand
   while (root->right != nullptr)
   {
     root = root->right;
   }
    return root;
    

}

struct node* deleteNode (struct node *root, int value){
    struct node*Ipre;
    //search for the node to be deleted
        if (root == nullptr){
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr){
            // return deleteNode(root, value);
            delete root;
            return nullptr;
        }

        if (value < root->data){
            root->left = deleteNode(root->left, value);

        } else if (value > root->data){
           root->right = deleteNode(root->right, value);
        }
   

         //deletion strategy
         else {
         // you can oley delete with inorder predecessor/pre or inorder sucessor/post.
         //yeh root woh hai jo change hote rahegii iteration ke waqt - like left subtree root or right subtree root
         Ipre = inPredecessor(root);
         root->data = Ipre->data;
         root->left = deleteNode(root->left, Ipre->data);

         }
         return root;
    
}



int main(){
   
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


    inorderTraverse(p);
    cout<<endl;
    deleteNode(p, 50);
    cout<<"the root data!"<<p->data<<endl;
    inorderTraverse(p);


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
    return 0;
}