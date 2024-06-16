#include <iostream>
using namespace std;

struct stack
{
   int size;
   int top;
   int *arr;
};

bool isEmpty (struct stack *sp){
   //no need to write the necessary just write the true value for function
   return (sp->top == -1);
}


bool isFull (struct stack *sp){
   //no need to write the necessary just write the true value for function
   return (sp->top == sp->size-1);
}


void push (struct stack *ptr, int val){
    if(isFull(ptr)){
        cout<<"The stack is Underflow"<<endl;
        // return -1;
    }else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        cout<<"The element"<<val<<"pushed on the stack"<<endl;
    }

}


int pop (struct stack *ptr){
    if(isEmpty(ptr)){
        cout<<"The stack is Overflow";
        return -1;
    }else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        cout<<"The element "<< val <<" poped out from the stack"<<endl;
        return val;
    }

}


int peek (struct stack *sp, int i){
   int arrayInd = sp->top - i + 1;
   if (arrayInd < 0){
    cout<<"Invalid value";
   }else {
    return sp->arr[arrayInd];
   }

   return -1;
};


int stackTop (struct stack*sp){
    return sp->arr[sp->top+1];
}


int stackbottom (struct stack*sp){
    return sp->arr[0];
}


int main(){
    struct stack *sp = new stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int [sp->size];

    push(sp, 46);
    push(sp, 76);
    push(sp, 6);
    push(sp, 15);

    pop(sp);


    for (int j = 1; j <= sp->top+1; j++)
    {
         cout << "The value at position " << j << " is: " << peek(sp, j) << endl;
    };
    
    
    cout << "The Top Of stack "<<stackTop(sp)<< endl;
    cout << "The bottom Of stack "<<stackbottom(sp)<< endl;
 
   return 0;
}