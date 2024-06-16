#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*next;
};

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
       // Handle memory allocation failure
    cout << "Memory allocation failed!" << endl;
    }else 
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    cout<<"the data " <<  data <<" is pushed in stack"<<endl;
    return top;
}


// int pop (struct node ** top){
//      struct node * ptr = *top;
//     if(isEmpty(*top)){
//     //  return -1;
//     }else 
//     *top = (*top)->next;
//     int x = ptr->data;
//     cout<<"the data " << x <<" is poped out from stack"<<endl;
//     delete ptr;
//     return x;
// }


struct node * pop (struct node * top){
     struct node * ptr = top;
    if(isEmpty(top)){
    //  return -1;
    }else 
    top = top->next;
    int x = ptr->data;
    cout<<"the data " << x <<" is poped out from stack"<<endl;
    delete ptr;
    return top;
}


int peek(struct node*top, int pos) {
    struct node *ptr = top;
    for (int i = 0; (i < pos-1 && ptr !=nullptr); i++)
    {
        ptr = ptr->next;
    }
        if(ptr != nullptr){
            return ptr->data;
        }else{
            return -1;
        } 
}

int stackTop(struct node*top){
    return top->data;
}


int stackBottom(struct node*top){
    struct node * ptr = top;
    while (ptr != nullptr){
        ptr = ptr->next;
        return ptr->data;
    }
   
}

int main(){
    struct node * top = nullptr;
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
    top = push(top, 19);//bottom
    top = push(top, 12);
    top = push(top, 15);
    top = push(top, 7);//head
    top = push(top, 76);//head
    // linkListTraverse(top);
    // cout << "Linked list after the deletion at top:" << endl;
    // top = pop(top);
    // int element = pop(&top);
    linkListTraverse(top);
    // cout << "the value at position 1 is :"<<peek(top, 1) << endl;

    for (int i = 1; i <= 5; i++)
       cout << "the value at position "<<i<<" is: " <<peek(top, i) << endl;
    {
        /* code */
    }
    

    cout << "the top item of stack is : "<<stackTop(top) << endl;

    cout << "the bottom item of stack is :"<<stackBottom(top) << endl;





    return 0;

}




//chat gpt code for checking

// #include <iostream>
// using namespace std;

// struct node {
//     int data;
//     struct node *next;
// };

// void linkListTraverse(struct node *ptr) {
//     while (ptr != NULL) {
//         cout << ptr->data << endl;
//         ptr = ptr->next;
//     }
// }

// bool isEmpty(struct node *top) {
//     return top == nullptr;
// }

// bool isFull(struct node *ptr) {
//     struct node *n = new node;
//     return n == nullptr;
// }

// struct node *push(struct node *top, int data) {
//     struct node *ptr = new node;
//     if (ptr == nullptr) {
//         // Handle memory allocation failure
//         cout << "Memory allocation failed!" << endl;
//         // You may want to return top or nullptr to indicate an error.
//     } else {
//         ptr->data = data;
//         ptr->next = top;
//         top = ptr;
//         cout << "the data " << data << " is pushed in stack" << endl;
//     }
//     return top;
// }

// struct node *pop(struct node *top) {
//     struct node *ptr = top;
//     if (isEmpty(top)) {
//         // Handle underflow condition
//         cout << "Stack is empty, cannot pop!" << endl;
//     } else {
//         top = top->next;
//         int x = ptr->data;
//         cout << "the data " << x << " is popped out from stack" << endl;
//         delete ptr;
//     }
//     return top;
// }

// int main() {
//     struct node *top = nullptr;

//     cout << "Linked list before insertion:" << endl;
//     linkListTraverse(top);

//     cout << "Linked list after the insertion at top:" << endl;
//     top = push(top, 99); // bottom
//     top = push(top, 59);
//     top = push(top, 69);
//     top = push(top, 39); // head
//     linkListTraverse(top);

//     cout << "Linked list after the deletion at top:" << endl;
//     top = pop(top);
//     linkListTraverse(top);

//     return 0;
// }
