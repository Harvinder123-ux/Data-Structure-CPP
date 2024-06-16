// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     struct Node*next;
// };

// void linkTraverse (struct Node * next){
//     while (next != NULL){
//     cout<<"the Element is: "<<next->data<<endl;
//     next = next -> next;
//     }
   
// }

// int main(){
//     struct Node*head;
//     struct Node*second;
//     struct Node*third;
//     struct Node*fourth;

//     head = new Node;
//     second = new Node;
//     third = new Node;
//     fourth = new Node;

//     head->data = 21;
//     head->next = second;

//     second->data = 56;
//     second->next =  third;

//     third->data = 61;
//     third->next =  fourth;

//     fourth->data = 71;
//     fourth->next = NULL;

//     linkTraverse(head);
    

//     return 0;

// }

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void linkListTraverse(struct Node* ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node* insertElement(struct Node* head, int data)
{
    struct Node* ptr = new Node;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

int main()
{
    // this is the creation of a linked list

    struct Node* head;
    struct Node* second;
    struct Node* third;

    // Allocate nodes for the linked list in the heap
    head = new Node;
    second = new Node;
    third = new Node;

    // link first and second node
    head->data = 7;
    head->next = second;

    // link second and third node
    second->data = 8;
    second->next = third;

    // terminate list at the third node
    third->data = 11;
    third->next = NULL; // Use nullptr instead of null

    cout << "Linked list before insertion:" << endl;
    linkListTraverse(head);

    // Update head with the new head returned by insertElement
    head = insertElement(head, 88);

    cout << "Linked list after insertion:" << endl;
    linkListTraverse(head);

    return 0;
}
