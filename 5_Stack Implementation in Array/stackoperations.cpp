#include <iostream>
using namespace std;

struct stack
{
    int size; //max size of my array
    int top;  //the topmost element
    int *arr; //pointer used for dynamically memory allocate in the heap
};

// this function checks whether the given stack is full or empty (return value true if the stack is empty and false otherwise)
bool isEmpty(struct stack *s)
{
    return (s->top == -1);
}

// this function checks whether the given stack is full or empty (return value true if the stack is full and false otherwise)
bool isFull(struct stack *s)
{
    return (s->top == s->size - 1);
}

// this function pushes an element onto the stack
void push(struct stack *s, int val)
{
    // check if the stack is full
    if (isFull(s))
    {
        cout << "The Stack is FULL - can't Perform Push Operation" << endl;
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        cout << "Element " << val << " pushed onto the stack" << endl;
    }
}

// this function pops an element from the stack
int pop(struct stack *s)
{
    // check if the stack is empty
    if (isEmpty(s))
    {
        cout << "The Stack is EMPTY - can't Perform Pop Operation" << endl;
        return -1; // return a default value to indicate failure
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        cout << "Element " << val << " popped from the stack" << endl;
        return val;
    }
}

int main()
{

    struct stack *s = new stack; // stack pointer that stores the address of the stack structure
    s->size = 10;                // set the size of the stack
    s->top = -1;                 // as of now, the stack is empty
    s->arr = new int[s->size];   // create an array on the heap for the stack

    // perform push operations
    push(s, 7);
    push(s, 13);
    push(s, 42);

    // perform pop operations
    pop(s);
    pop(s);
    pop(s);

    return 0;
}

//according to me and harry bhai code

// #include <iostream>
// using namespace std;

// struct stack
// {
//     int size; //max size of my array
//     int top;  //the topmost element
//     int *arr; //pointer used for dynamically memory allocate in the heap
// };


// //this function check whether the given stack is full or empty (return value true if stack is empty and else false)
// bool isEmpty( struct stack *s){  
//     if (s->top == -1){
//         return true;
//     }else {
//         return false;
//     }

// }

// //this function is also check whether the given stack is full or empty (return value true if stack is full and else false)
// bool isFull( struct stack *s){ 
//     if (s->top == s->size-1){
//         return true;
//     }else {
//         return false;
//     }

// }

// //now create the puch function instead of  write in the main
// void push(struct stack *ptr, int val) {
//     // we can also use s instead of ptr; they are just pointers
//     if (isFull(s)) {
//         cout << "The Stack is FULL - can't Perform Push Operation" << endl;
//     } else {
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }

// //now create the pop function instead of writing it in the main
// int pop(struct stack *ptr) {
//     // we can also use s instead of ptr; they are just pointers
//     if (isEmpty(s)) {
//         cout << "The Stack is EMPTY - can't Perform Pop Operation" << endl;
//         return -1; // return a default value to indicate failure
//     } else {
//         int val = ptr->arr[ptr->top];
//         ptr->top--;
//          cout<<"element poped from stack"<<endl;  
//         return val;
//     }
// }

// int main(){
   
//     struct stack *s; //stack pointer that store the adress of stack structure
//         s->size = 10; //add the size of stack 
//         s->top = -1; //as of now stack is empty
//         s->arr = new int[s->size]; //used for create array in heap 
//         //after this stack has been created successfull

    
    
//     // //in this if statements used for check the stack is overflowed or else statement used for push element in stack if it's not full
//     push(s, 7);  
//     //in this if statements used for check the stack is underflowed or else statement used for pop element from stack if it's not empty
//     pop(s);

//     return 0;
// }