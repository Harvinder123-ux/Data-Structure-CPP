#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node*next;
};


// function for traversing in the circulary link list
void linkTraverse(struct Node*head){
    struct Node* ptr = head;
    do
    {
        cout<<"the Element Is:"<<ptr->data<<endl;
        ptr = ptr->next;

    } while (ptr != head);

    //for while loop you have to do this
    // cout<<"the Element Is:"<<ptr->data<<endl;
    // ptr = ptr->next;
    // while (ptr != head)
    // {
    //     cout<<"the Element Is:"<<ptr->data<<endl;
    //     ptr = ptr->next;
    // }
}

//insertion in circulary link list - time complexity O(1);
struct Node* deleteCircleLinkList (struct Node * head){
    struct Node* ptr = head;
    struct Node * p = head;
    while (p-> next != head)
    {
      p = p->next;
    } 
    p->next = head -> next;
    head = head->next;
    delete ptr;
    return head;
}

//function for Inserting element between in the Circulary Link list
// struct Node* deleteBetween(struct Node* head){
//     struct Node * ptr = head;
//     struct Node * p = head-> next;
//     for (int i = 0; i < index - 1; i++)
//     {
//        ptr = ptr->next;
//        p = p->next;
//     }
   
//     ptr->next = p->next;
//     head = p->next;        //not necessary just Update head to the new head if we delete node at 0 index
//     delete p;
//     return head;
// }


//function for Inserting element at the end in the Circulary Link list
struct Node* deleteAtEnd(struct Node* head){
    struct Node * ptr = head;
    struct Node * prev = nullptr;
   do
    {
       prev = ptr;
       ptr = ptr->next;
    } while (ptr->next != head);
    prev->next = head;
    delete ptr; 
    return head;
}


//function for Inserting element at the end in the Circulary Link list
struct Node* deleteGivenValue(struct Node* head, int value){
    struct Node * ptr = head;
    struct Node * p = head->next;
    while (p->data != value && p->next != nullptr)
    {
       p = p->next;
       ptr = ptr->next;
    }
    ptr->next = p->next;
    delete p; 
    return head;
}


int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;

    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    head->data = 6;
    head->next = second;
    
    second->data = 8;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth -> data = 13;
    fourth->next = head;

    cout << "Linked list before:" << endl;
    linkTraverse(head);

    // cout << "Linked list after the delete at first:" << endl;
    // head = deleteCircleLinkList(head);
    // linkTraverse(head);

    // cout << "Linked list after insertion Between:" << endl;
    // head = deleteBetween(head, 1);
    // linkTraverse(head);

    cout << "Circular Linked list after the deletion at the end :" << endl;
    head = deleteAtEnd(head);
    linkTraverse(head);

    // cout << "Circular Linked list after the deletion at given value :" << endl;
    // head = deleteGivenValue(head, 13);
    // linkTraverse(head);

    



    return 0;

}