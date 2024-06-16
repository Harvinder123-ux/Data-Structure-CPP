#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

//LinkList traverse
void linkListTraverse (struct Node* ptr){
  while (ptr != NULL){
    cout<<ptr->data<<endl;
    ptr = ptr -> next;
  }

}

//insert at the first
struct Node * insertElement (struct Node* head, int data){
  struct Node*ptr = new Node;
  ptr->next = head;
  ptr->data = data;
  return ptr;
}

//insert Between
struct Node * insertBetween (struct Node* head, int data, int index){
  struct Node*ptr = new Node;
   struct Node*p = head;
   int i = 0;
  while (i != index-1){
  p = p -> next;
  i++;
  }
  ptr->data = data;
  ptr->next = p -> next;
  p->next = ptr;
  return head;
}


//insert at the end
struct Node * insertEnd (struct Node* head, int data){
  struct Node*ptr = new Node;
  struct Node*p = head;
  ptr->data = data;
  while (p->next != nullptr){
  p = p -> next;
  }
  p->next = ptr;
  ptr->next = nullptr;
  
  return head;
}


//insert after the node
struct Node * insertAfterNode (struct Node* head, struct Node* prevNode, int data){
  struct Node*ptr = new Node;
  ptr->data = data;
  ptr->next = prevNode->next;
  prevNode->next = ptr;
  
  return head;
}


int main()
{
    //this the creation of link list

    struct Node* head;
    struct Node* second;
    struct Node* third;

    // Allocate nodes for the linked list in the heap
    head = new Node;
    second = new Node;
    third = new Node;
    

    //link first and second node
    head->data = 7;
    head->next = second;

    //link second and third node
    second->data = 8;
    second->next = third;

    //terminate list at the third node
    third->data = 11;
    third->next = nullptr;  // Use nullptr instead of null

    cout << "Linked list before insertion:" << endl;
    linkListTraverse(head);

    cout << "Linked list after the insertion at first:" << endl;
    head = insertElement(head, 3);
    linkListTraverse(head);

    // Insert a new node between the first and second nodes
    // head = insertBetween(head, 77, 1);

    // cout << "Linked list after insertion:" << endl;
    // linkListTraverse(head);


    // cout << "Linked list after insertion At the End:" << endl;
    // head = insertEnd(head, 47);
    // linkListTraverse(head);

    cout << "Linked list after the Node insertion:" << endl;
    head = insertAfterNode(head, second, 33);
    linkListTraverse(head);

    return 0;
}


// struct Node* insertBetween(struct Node* head, int data, int index)
// {
//     // Step 1: Create a new node
//     struct Node* ptr = new Node;

//     // Step 2: Initialize a pointer to traverse the linked list
//     struct Node* p = head;

//     // Step 3: Initialize a variable to keep track of the current position
//     int i = 0;

//     // Step 4: Traverse the linked list until the node just before the desired index
//     while (i != index - 1 && p != nullptr)
//     {
//         p = p->next;  // Move to the next node
//         i++;         // Increment the position counter
//     }

//     // Step 5: Check if the index is out of bounds
//     if (p == nullptr)
//     {
//         cout << "Index out of bounds." << endl;
//         delete ptr; // Deallocate memory if index is out of bounds
//         return head; // Return the original head unchanged
//     }

//     // Step 6: Update the new node with the provided data
//     ptr->data = data;

//     // Step 7: Link the new node to the rest of the linked list
//     ptr->next = p->next;

//     // Step 8: Update the next pointer of the node just before the desired index
//     p->next = ptr;

//     // Step 9: Return the head of the linked list
//     return head;
// }
