#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *f = nullptr;
struct node *r = nullptr;

void linkListTraversal(struct node *q)
{
    while (q != nullptr)
    {
        cout << q->data << " ";
        q = q->next;
    }
}

// bool isEmpty (struct node*q){
//     return (f == nullptr);
// }

// bool isFull (struct node*p){
//     return (p == nullptr);
// }

void enqueue(int val)
{
    struct node *n = new node;
    if (n == nullptr)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        n->data = val;
        n->next = nullptr;

        if (f == nullptr || r == nullptr)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
            cout << "the :" << val << " - enque in the link listQueue" << endl;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == nullptr)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        f = f->next;
        val = ptr->data;
        delete ptr;
        cout << "the :" << val << " - deque in the link listQueue" << endl;
    }
    return val;
}

int main()
{

    linkListTraversal(f);

    dequeue();

    enqueue(17);
    enqueue(55);
    enqueue(34);

    dequeue();

    linkListTraversal(f);

    return 0;
}