#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*next;
};

void display (struct node * ptr){
    while (ptr != nullptr)
    {
        cout<<ptr->data << " ";
        ptr = ptr ->next;
    }
    cout<<endl;
    
}

// struct node * insert (struct node * head, int data){
//     struct node * ptr = new node;
//     ptr -> data = data;

//     ptr->next = head;
//     return ptr;

// }


// struct node * insertBetween (struct node * head, int data, int index){
   
//     struct node * p = new node;
//     struct node * ptr = head;
  
//     int i = 0;
//     while (i != index-1)
//     {
//         ptr = ptr->next;
//         i++;
//     }
//     p -> data = data;
//     p-> next = ptr->next;
//     ptr->next = p;

//     return head;
// }


// struct node * insertBetween (struct node * head, int data){
   
//     struct node * p = new node;
//     struct node * ptr = head;
  
//     int i = 0;
//     while (ptr->next != nullptr)
//     {
//         ptr = ptr->next;
//     }
//     p -> data = data;
//     p-> next = nullptr;
//     ptr->next = p;

//     return head;
// }


struct node * insertBetween (struct node * head, struct node *prevNode, int data){
   
    struct node * p = new node;
    struct node * ptr = head;
    p -> data = data;
    p -> next = prevNode->next;
    prevNode->next = p;

    return head;
}


int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head = new node;
    second = new node;
    third = new node;
    fourth = new node;

    head -> data = 7;
    head -> next = second;
    
    second -> data = 10;
    second -> next = third;

    third ->data = 13;
    third -> next = fourth;

    fourth ->data = 17;
    fourth -> next = nullptr;

    display (head);
    // head = insert(head, 5);
    cout<<"After the insertion at the end in linklist"<<endl;
    // head = insertBetween(head, 45, 4);

    // head = insertBetween(head, 47);
    head = insertBetween(head, third,  14);
    
    display(head);


    return 0;
}