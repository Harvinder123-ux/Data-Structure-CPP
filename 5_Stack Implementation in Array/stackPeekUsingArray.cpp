#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct stack
{
    int size; // max size of my array
    int top;  // the topmost element
    int *arr; // pointer used for dynamically memory allocate in the heap
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


int peek(struct stack *s, int i)
{
    int arrayInd = s->top - i + 1; //this formula work with all element using the (top-i) formula with the positions and indexes
    if (arrayInd < 0)
    {
        cout << "invalid position value for peek";
    }
    else
    {
        return s->arr[arrayInd];
    }

    return -1;
};

int main()
{

    struct stack *s = new stack; // stack pointer that stores the address of the stack structure
    s->size = 10;                // set the size of the stack
    s->top = -1;                 // as of now, the stack is empty
    s->arr = new int[s->size];   // create an array on the heap for the stack

    // perform push operations
    push(s, 7);
    push(s, 13);
    push(s, 42);// the last one poped out

    // perform pop operations
     pop(s); // poped out the last one
    // pop(s);
    // pop(s);

    /// for loop used for print all the values in stack
    for (int j = 1; j <=s->top+1; j++)
    {
        cout << "The value at position " << j<< " is: " << peek(s, j) << endl;
    }

    return 0;

}