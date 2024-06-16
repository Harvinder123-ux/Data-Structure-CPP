#include <iostream>
using namespace std;

struct queueCircular
{
    int size;
    int f;
    int r;
    int *arr;
};

bool isFull(struct queueCircular *q)
{
    return ((q->r + 1) % q->size == q->f);
}

bool isEmpty(struct queueCircular *q)
{
    return (q->r == q->f);
}

void enQueue(struct queueCircular *q, int val)
{
    if (isFull(q))
    {
        cout << "the circularQueue is full" << endl;
    }
    else
    {
        q->r = (q->r) % q->size;
        q->arr[q->r] = val;
        cout << "the :" << val << " - added in the circular circularQueue" << endl;
    }
}

int deQueue(struct queueCircular *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        cout << "the circularQueue is empty" << endl;
    }
    else
    {

        val = q->arr[q->f];
        q->f = (q->f) % q->size;
        cout << "the :" << val << " - removed in the circular circularQueue" << endl;
    }
    return val;
}

int main()
{
    struct queueCircular *q = new queueCircular;
    q->size = 3;
    q->f = q->r = 0;
    q->arr = new int[q->size];

    enQueue(q, 77);
    enQueue(q, 18);

    // deQueue(q);
    cout << "dequeued the element:" << deQueue(q) << endl;
    cout << "dequeued the element:" << deQueue(q) << endl;
    cout << "dequeued the element:" << deQueue(q) << endl;
    // cout<<"dequeued the element:"<<deQueue(q)<<endl;

    enQueue(q, 4);
    enQueue(q, 5);

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