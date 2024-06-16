#include <iostream>
using namespace std;

struct queue {
    int size;
    int f;
    int r;
    int*arr;
};


// void queueTraversal(struct queue*q){
//     while(q->r == q->size-1){
    
//     }
    
// }
bool isFull (struct queue*q){
    return (q->r == q->size -1);
}


bool isEmpty (struct queue*q){
    return (q->f == q->r);
}

void enQueue (struct queue * q, int val){
    if(isFull(q)){
        // cout<<"the queue is full"<<endl;
    }else {
        q->r = q->r+1;
        q->arr[q->r] = val;
         cout<<"the :" <<val<<" - added in the queue"<<endl;
    }
}

int deQueue (struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        // cout<<"the queue is empty! there's no element avaialble to dequeue"<<endl;
    }else {
        q->f++; //put frontend f to the index 0 in the array
        a = q->arr[q->f]; //a use for dequeue that convert array 0 index into the -1
        cout<<"the  :" <<a<<" - dequeued from the queue"<<endl;

          //chatgpt version
         // a = q->arr[q->f + 1];
        // q->f++;
       // cout << "the  : " << a << " - dequeued from the queue" << endl;
    }
     return a;
}


int main(){
    struct queue *q = new queue;
    q->size = 10;
    q->f = q->r = -1;
    q->arr = new int [q->size];



    enQueue(q, 33);
    enQueue(q, 7);
    enQueue(q, 15);
    enQueue(q, 18);
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    cout<<"dequeued the element:"<<deQueue(q)<<endl;

    if(isEmpty(q)){
        cout<<"The queue is empty"<<endl;
    }
    
    if(isFull(q)){
        cout<<"The queue is Full"<<endl;
    }

    delete[] q->arr; // Don't forget to free the memory allocated for the array
    delete q; // Don't forget to free the memory allocated for the queue structure


    return 0;
}




//chat GPT

// #include <iostream>
// using namespace std;

// struct queue {
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// bool isFull(struct queue *q) {
//     return (q->r == q->size - 1);
// }

// bool isEmpty(struct queue *q) {
//     return (q->f == q->r);
// }

// void enQueue(struct queue *q, int val) {
//     if (isFull(q)) {
//         cout << "the queue is full" << endl;
//     } else {
//         q->r = q->r + 1;
//         q->arr[q->r] = val;
//         cout << "the : " << val << " - added in the queue" << endl;
//     }
// }

// int deQueue(struct queue *q) {
//     int a = -1;
//     if (isEmpty(q)) {
//         cout << "the queue is empty! there's no element available to dequeue" << endl;
//     } else {
//         a = q->arr[q->f + 1];
//         q->f++;
//         cout << "the  : " << a << " - dequeued from the queue" << endl;
//     }
//     return a;
// }

// int main() {
//     struct queue *q = new queue;
//     q->size = 10;
//     q->f = q->r = -1;
//     q->arr = new int[q->size];

//     enQueue(q, 33);
//     enQueue(q, 7);
//     enQueue(q, 15);
//     enQueue(q, 18);

//     deQueue(q);

//     delete[] q->arr; // Don't forget to free the memory allocated for the array
//     delete q; // Don't forget to free the memory allocated for the queue structure

//     return 0;
// }
