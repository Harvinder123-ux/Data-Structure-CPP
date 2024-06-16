#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*next;

};


void linkTraverse (struct node*ptr){
   while (ptr != nullptr)
   {
    cout<<ptr->data<<endl;
    ptr = ptr->next;
   }
   
    
}



int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head = new node;
    second = new node;
    third = new node;

    head->data = 17;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 19;
    third->next = nullptr;
     

     linkTraverse(head);





    return 0;
}