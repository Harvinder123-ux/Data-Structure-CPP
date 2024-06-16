#include <iostream>
using namespace std;

// Define a structure for the stack
struct stack
{
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is full
bool isFull(struct stack *sp)
{
    return (sp->top == sp->size - 1);
}

// Function to check if the stack is empty
bool isEmpty(struct stack *sp)
{
    return (sp->top == -1);
}

// Function to push an element onto the stack
void stackPush(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        cout << "Cannot insert the element! Stack is full." << endl;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = val;
        cout << "Element " << val << " pushed onto the stack." << endl;
    }
}

// Function to pop an element from the stack
int stackPop(struct stack *sp)
{
    int val;
    if (isEmpty(sp))
    {
        cout << "Cannot pop the element! Stack is empty." << endl;
        return 0;
    }
    else
    {
        val = sp->arr[sp->top];
        sp->top--;
        cout << "Element " << val << " deleted from the stack." << endl;
    }
    return 1;
}

// Function to peek at an element in the stack
int stackPeek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0 || arrayInd > sp->top)
    {
        cout << "Invalid position." << endl;
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int main()
{
    // Create a stack
    struct stack *sp = new stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int[sp->size];

    // Perform stackPush operations
    stackPush(sp, 7);
    stackPush(sp, 13);
    stackPush(sp, 42);

    // Perform pop operations
    // stackPop(sp);
    // stackPop(sp);
    // stackPop(sp);

    // Print the values at different positions in the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        cout << "The value at position " << j << " is: " << stackPeek(sp, j) << endl;
    }

    delete[] sp->arr; // Free the dynamically allocated memory for the stack array
    delete sp;        // Free the memory for the stack structure

    return 0;
}
