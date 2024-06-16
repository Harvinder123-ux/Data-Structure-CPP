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
struct Node* insertCircleLinkList (struct Node * head, int data){
    struct Node* ptr = new Node;
    ptr->data = data;
    struct Node* p = head->next;

    while (p->next != head){
        p = p->next;
    }

    //due to loop p points on the last node of the circular link list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

//function for Inserting element between in the Circulary Link list
struct Node* insertBetween(struct Node* head, int data , int index){
    struct Node * ptr = new Node;
    ptr -> data = data;
    struct Node * p = head;
    for (int i = 0; i < index - 1; i++)
    {
       p = p->next;
    }
   
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
//function for Inserting element at the end in the Circulary Link list
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node * ptr = new Node;
    ptr -> data = data;
    struct Node * p = head->next;
    while (p->next != head)
    {
       p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

//function for Inserting element at after the node in the Circulary Link list
struct Node* insertAtAfter(struct Node* head, struct Node* prevNode, int data){
    struct Node * ptr = new Node;
    ptr-> data = data;

    //additional from the chatGpt
    if (prevNode == nullptr) {
        cout << "Previous node cannot be nullptr." << endl;
        return head;
    }
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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

    // cout << "Linked list after the insertion at first:" << endl;
    // head = insertCircleLinkList(head, 3);
    // head = insertCircleLinkList(head, 99);
    // head = insertCircleLinkList(head, 54);
    // linkTraverse(head);

    // cout << "Linked list after insertion Between:" << endl;
    // head = insertBetween(head, 78, 3);
    // linkTraverse(head);

    // cout << "Circular Linked list after the insertion at the end :" << endl;
    // head = insertAtEnd(head, 47);
    // linkTraverse(head);

    cout << "Circular Linked list after the insertion after the Node :" << endl;
    head = insertAtAfter(head, third, 66);
    linkTraverse(head);



    return 0;

}