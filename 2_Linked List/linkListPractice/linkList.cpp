#include <iostream>
using namespace std;
struct node {
    int data;
    struct node*next;
};

void linkTraverse(struct node*p){
     while (p != nullptr)
     {
       cout<<p->data<<endl;
       p = p->next;
     }     
}

//insertion operation
struct node*insertElement(struct node*head, int data){
    struct node*ptr = new node;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//insertion operation at between
// struct node*insertElementBTW(struct node*head, int data, int index){
//     struct node*ptr = new node;
//     struct node*p = head;
//     // ptr = p->next;
//     ptr->data = data;

//     int i = 0;
//     while (i != index-1)
//     {
//        p = p->next;
//        i++;
//     }
    
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

struct node*insertElementEnd(struct node*head, int data){
    struct node*ptr = new node;
    struct node*p = head;
    // ptr = p->next;
    ptr->data = data;

    // int i = 0;
    while (p->next != nullptr)
    {
       p = p->next;
    }
    
    ptr->next = nullptr;
    p->next = ptr;
    return head;
}


struct node*insertElementAfterNode(struct node*head, struct node*prev, int data){
    struct node*ptr = new node;
    struct node*p = head;
    // ptr = p->next;
    ptr->data = data;

    ptr->next = prev->next;
    prev->next = ptr;
    return head;
}

int main(){
    struct node*head;
    struct node*second;
    struct node*third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 33;
    head->next = second;

    second->data = 17;
    second->next = third;
 
    third->data = 49;
    third->next = nullptr;


    linkTraverse(head);
    cout<<"after the insertion of element at first"<<endl;


    // //insert element at first
    // head = insertElement(head, 10);
    // linkTraverse(head);

    // //insert element at  Between
    // cout<<"after the insertion of element at Between"<<endl;
    // head = insertElementBTW(head, 15, 2);
    // linkTraverse(head);

    

    // //insert element at  Between
    // cout<<"after the insertion of element at End"<<endl;
    // head = insertElementEnd(head, 11);
    // linkTraverse(head)
    
    
    cout << "Linked list after the Node insertion:" << endl;
    head = insertElementAfterNode(head, second, 88);
    linkTraverse(head);


    return 0;
}