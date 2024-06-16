#include <iostream>
using namespace std;

struct Node {
        int data;
        struct Node* next;
};

//traversing 
void linkListTraverse(struct Node*ptr){
    while (ptr != nullptr){
    cout<<"the Element is: "<<ptr->data<<endl;
    ptr = ptr -> next;

    }
};
 
//inserting at first
struct Node*insertAtFirst(struct Node* head, int data ){
    struct Node *ptr = new Node;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//inserting btw
struct Node*insertElementBetween(struct Node*head, int data, int index){
    struct Node *ptr = new Node;
    struct Node*p = head;
    int i = 0;

    while (i != index-1){
       p = p->next;
       i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


//inserting at the end
struct Node*insertAtEnd(struct Node*head, int data){
    struct Node *ptr = new Node;
    struct Node*p = head;
    ptr->data = data;
    
    while (p->next != nullptr){
       p = p->next;
    }
    p->next = ptr;
    ptr->next = nullptr;
  

    return head;
}

//inserting after the node
struct Node*insertAtEnd(struct Node*head, struct Node*prevNode, int data){
    struct Node *ptr = new Node;
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}



int main(){
    
    struct Node*head;
    struct Node*second;
    struct Node*third;

    head = new Node;
    second = new Node;
    third= new Node;

    head->data = 8;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 17;
    third->next = nullptr;
    


    cout << "Linked list before insertion:" << endl;
    linkListTraverse(head);

    // cout << "Linked list after the insertion at first:" << endl;
    // head = insertAtFirst(head, 3);
    // linkListTraverse(head);

    // cout << "Linked list after the insertion element between:" << endl;
    // head = insertElementBetween(head, 85, 1);
    // linkListTraverse(head);

    // cout << "Linked list after the insertion at the last:" << endl;
    // head = insertAtEnd(head, 76);
    // linkListTraverse(head);

    cout << "Linked list after the insertion after the Node:" << endl;
    head = insertAtEnd(head, third, 56);
    linkListTraverse(head);


    return 0;
}