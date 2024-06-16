#include <iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int *arr;
};

bool isEmpty (struct stack*ptr){
   return (ptr->top == -1);
}


bool isFull (struct stack*ptr){
   return (ptr->top == ptr->size-1);
}


int main(){
    struct stack*s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    s->arr[0] = 10;
    s->top++;

    
    s->arr[1] = 20;
    s->top++;

    
    s->arr[2] = 30;
    s->top++;

    
    if (isEmpty(s)) {
        // Perform actions when the stack is empty
         cout<<"the stack is empty! you can push"<<endl;
    } else {
        // Perform actions when the stack is not empty
        cout << "Performing actions when the stack is not empty." << endl;
    }

     if (isFull(s)) {
        // Perform actions when the stack is empty
        cout<<"the stack is full! you can't push Now";
    } else {
        // Perform actions when the stack is not empty
        cout << "Performing actions when the stack is not Full." << endl;
    }




    return 0;
}