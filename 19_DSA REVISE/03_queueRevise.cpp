#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

// jab hamar q-> r jp koi enqueue ke liye use hota haa woh size-1 mean full index par pahunch jayega
bool isFull(struct queue *q)
{
    return (q->r == q->size - 1);
}

// jab hamare dono f, r variables or ptr starting meing honge
bool isEmpty(struct queue *q)
{
    return (q->f == q->r);
}

void enQueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        cout << "cant insert! queue is already full";
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        cout << "the :" << val << " - added in the queue" << endl;
    }
}

int deQueue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        /* code */
        cout << "cant enqueue! queue is already empty";
    }
    else
    {
       
        a = q->arr[q->f];
        q->f++;
        cout << "the  :" << a << " - dequeued from the queue" << endl;
    }
    return a;
}

int main()
{
    struct queue *q = new queue;
    q->size = 10;
    q->f = q->r = -1;
    q->arr = new int[q->size];

    enQueue(q, 33);
    enQueue(q, 7);
    enQueue(q, 15);
    enQueue(q, 18);
    cout << "dequeued the element:" << deQueue(q) << endl;
    cout << "dequeued the element:" << deQueue(q) << endl;
    cout << "dequeued the element:" << deQueue(q) << endl;
    cout << "dequeued the element:" << deQueue(q) << endl;
    cout << "dequeued the element:" << deQueue(q) << endl;

    if (isEmpty(q))
    {
        cout << "The queue is empty" << endl;
    }

    if (isFull(q))
    {
        cout << "The queue is Full" << endl;
    }

    delete[] q->arr; // Don't forget to free the memory allocated for the array
    delete q;        // Don't forget to free the memory allocated for the queue structure

    return 0;
}