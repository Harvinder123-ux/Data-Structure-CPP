#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void linkListTraverse (struct Node* ptr){
  while (ptr != NULL){
    cout<<ptr->data<<endl;
  ptr = ptr -> next;
  }

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
    third->next = NULL;  // Use nullptr instead of null

    linkListTraverse(head);

    return 0;
}
