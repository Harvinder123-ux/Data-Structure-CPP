#include <iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int *arr;
};

bool isEmpty (struct stack*s){
   return (s->top == -1);
}


bool isFull (struct stack*s){
   return (s->top == s->size-1);
}


void push(struct stack * s, int val){
    if (isFull(s))
    {
       cout<<"cant insert stack is full";
    }else {
        s->top++;
        s->arr[s->top] = val;
    }
}



int pop (struct stack * s){
    int val;
    if (isEmpty(s))
    {
       cout<<"cant pop stack is Empty";
    }else {
       
        val = s->arr[s->top];
        s->top--;
    }
    return val;
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