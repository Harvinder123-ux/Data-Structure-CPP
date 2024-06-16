#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

bool isFull(struct queue *q)
{
    return (q->r == q->size - 1);
}

bool isEmpty(struct queue *q)
{
    return (q->r == q->f);
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        cout << "the queue is full" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        cout << "the queue is full" << endl;
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int main()
{
    struct queue *q = new queue;
    q->size = 200;
    q->f = q->r = 0;
    q->arr = new int[q->size];

    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0}, // 0
        {1, 0, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 0}, // 2
        {1, 0, 1, 0, 1, 0, 0}, // 3
        {0, 0, 1, 1, 0, 1, 1}, // 4
        {0, 0, 0, 0, 1, 0, 0}, // 5
        {0, 0, 0, 0, 1, 0, 0}  // 6
    };
    cout << i<<" ";
    visited[i] = 1;
    enqueue(q, i);
    
    while (!isEmpty(q))
    {
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {   
                cout << j<<" ";
                visited[j] = 1;
                enqueue(q, j);
                
            }
        }
    }

    return 0;
}