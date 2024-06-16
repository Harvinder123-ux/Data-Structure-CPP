#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void linkListTraverse(struct node *top)
{
    while (top != nullptr)
    {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

bool isEmpty(struct node *top)
{
    return top == nullptr;
}

bool isFull(struct node *top)
{
    struct node *n = new node;
    return n == nullptr;
}

struct node *push(struct node *top, int data)
{
    struct node *ptr = new node;
    if (ptr == nullptr)
    {
        cout << "cant insert stack is full";
    }
    else
    {
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        cout << "the data " << data << " is pushed in stack" << endl;
      
    }
    return top;
}

struct node *pop(struct node *top)
{
    struct node *ptr = top;
    if (isEmpty(top))
    {
        cout << "cant pop stack is already empty";
    }
    else
    {
        top = top->next;
        int x = ptr->data;
        cout << "Popped element: " << x << endl;
        delete ptr;
      
    }
   return top;
}

int main()
{
    struct node *top = nullptr;
    cout << "Linked list before insertion:" << endl;
    linkListTraverse(top);
    cout << "Linked list after the insertion at top:" << endl;
    top = push(top, 99); // bottom
    top = push(top, 59);
    top = push(top, 69);
    top = push(top, 39); // head
    // linkListTraverse(top);
    cout << "Linked list after the deletion at top:" << endl;
    top = pop(top);
    // int element = pop(&top);
    linkListTraverse(top);
    if (isEmpty(top))
    {
        // Perform actions when the node is empty
        cout << "the node is empty! you can push" << endl;
    }
    else
    {
        // Perform actions when the node is not empty
        cout << "Performing actions when the node is not empty." << endl;
    }

    if (isFull(top))
    {
        // Perform actions when the node is empty
        cout << "the node is full! you can't push Now";
    }
    else
    {
        // Perform actions when the node is not empty
        cout << "Performing actions when the node is not Full." << endl;
    }

    return 0;
}