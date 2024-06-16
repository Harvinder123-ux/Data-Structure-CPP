#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*next;
};
struct node * top = nullptr;

void linkListTraverse (struct node* ptr){
  while (ptr != NULL){
    cout<<ptr->data<<endl;
    ptr = ptr -> next;
  }
}

bool isEmpty (struct node * top){
   return top == nullptr;
}


//you can use the int for writing like harray bhai in c
bool isFull (struct node * ptr){
   struct node * n = new node;
   return n == nullptr;
}

struct node * push (struct node * top, int data){
    struct node * ptr = new node;
    if(ptr == nullptr){
    //  return -1;
    }else 
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    cout<<"the data " <<  data <<" is pushed in stack"<<endl;
    return top;
}

int pop (struct node * tp){
     struct node * ptr = tp;
    if(isEmpty(tp)){
    //  return -1;
    }else 
    top = tp->next;
    int x = ptr->data;
    cout<<"the data " << x <<" is poped out from stack"<<endl;
    delete ptr;
    return x;
}


// struct node * pop (struct node * top){
//      struct node * ptr = top;
//     if(isEmpty(top)){
//     //  return -1;
//     }else 
//     top = top->next;
//     int x = ptr->data;
//     cout<<"the data " << x <<" is poped out from stack"<<endl;
//     delete ptr;
//     return top;
// }

int main(){
   
    // struct node * second;
    // struct node * third;
    // struct node * fourth;

    // top = new node;
    // second = new node;
    // third = new node;
    // fourth = new node;

    // top->data = 17;
    // top->next = second;
    
    // second->data = 15;
    // second->next = third;

    // third->data = 25;
    // third->next = fourth;

    // fourth->data = 45;
    // fourth->next = nullptr;
    
    cout << "Linked list before insertion:" << endl;
    linkListTraverse(top);
    cout << "Linked list after the insertion at top:" << endl;
    top = push(top, 99);//bottom
    top = push(top, 59);
    top = push(top, 69);
    top = push(top, 39);//head
    // linkListTraverse(top);
    cout << "Linked list after the deletion at top:" << endl;
    // top = pop(top);
    int element = pop(top);
    linkListTraverse(top);


    return 0;

}



