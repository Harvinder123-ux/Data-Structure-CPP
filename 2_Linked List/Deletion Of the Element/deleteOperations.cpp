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

//delete at the first - case 1 - complexity always O(1)
struct Node * deleteFirstElement (struct Node* head, int data){
//   struct Node*ptr = new Node;
  struct Node*ptr = head; //Dono Connect ho jayenge first node se head bhi or ptr bhhi
  head = head->next;  // jo head hoga woh seedha next node se connect ho jayega or ptr reh jayege
  delete ptr;// jaha par unlinked ptr delete ho jayega
  return head;
}

//delete Between - case 2 - complexity always O(n)
struct Node * DeleteNodeBetween (struct Node* head,int index){
  struct Node*p = head; //Compiler se p Pointer liya jo head ko point kar raha hai
 

//  Mine Code
//    int i = 0; //initilize the loop at index at 0
//   while (i != index-1){
//   p = p -> next;
//   i++;
//   }
//   //while loop ki help se jab p index par pahunch jayega hum ek aur pointer mangwa lenge compiler se 
//   struct Node*q = p->next;// je pointer hoga q and yeh bhi point kar raha hoga next node(jisko hame delete krna hai) likewise p
//   p->next = q->next;//aur hum p-> next ko q->next node sath point kardenge paar wali node k saath
//   delete q; //frr q ko delete kar denge - lekin frr bhi p next waali paar node ko connect kar raha hoga

//Harry bhai code
 struct Node*q = head->next;
 for (int i = 0; i < index - 1; i++)
 {
    p = p->next;
    q = q->next;
 }
  p->next = q->next;
  delete q;
 
  return head;
}


//insert at the end
struct Node * deleteAtEnd (struct Node* head){
//   struct Node*q = head; 
//   struct Node*p = nullptr; // Node before the last node
//   // Traverse the list to find the last two nodes 
//   while (q->next != nullptr){
//     p = q;
//     q = q->next;
//   }
//   // Unlink the last node and delete it
//   p->next = nullptr;
//   delete q;
 // Return the updated head
//   return head;
// }


//Harry bhai code
struct Node*p = head;
 struct Node*q = head->next;
 while (q->next != nullptr)
 {
    p = p->next;
    q = q->next;
 }
  p->next = nullptr;
  delete q;
//   p->next = q->next;
//   delete q;
 
  return head;
}
 


//insert after the node
struct Node * deleteGivenValue (struct Node* head, int value){
//Harry bhai explaination
struct Node*p = head;
 struct Node*q = head->next;
 while (  q->next !=nullptr && q->data != value )
 {
    p = p->next;
    q = q->next;
 }
 if (q->data == value){
     p->next = q->next;
    delete q;
 }
 
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

    // cout << "Linked list after the deletion at first:" << endl;
    // head = deleteFirstElement(head, 3);
    // linkListTraverse(head);

    // Insert a new node between the first and second nodes
    head = DeleteNodeBetween(head, 2);
    cout << "Linked list after insertion:" << endl;
    linkListTraverse(head);


    // cout << "Linked list after deletion At the End:" << endl;
    // head = deleteAtEnd(head);
    // linkListTraverse(head);

    // cout << "Linked list after the deletion of given:" << endl;
    // head = deleteGivenValue(head, 8);
    // linkListTraverse(head);

    return 0;
}

