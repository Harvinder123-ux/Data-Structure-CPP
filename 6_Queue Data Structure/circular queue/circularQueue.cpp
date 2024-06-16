//the formula used - (i+1)%size = 
#include <iostream>
using namespace std;

struct circularQueue {
    int size;
    int f;
    int r;
    int  *arr;
};

// int isEmpty (struct circularQueue * q){
//     if (q->r == q->f){
    
//     }
//     return 0;
// }

// int isFull (struct circularQueue * q){
//     if ((q->r+1)%q->size == q->f){
    
//     }
//     return 0;
// }
int isEmpty(struct circularQueue *q) {
    return (q->r == q->f);
}

int isFull(struct circularQueue *q) {
    return ((q->r + 1) % q->size == q->f);
}


void enQueue(struct circularQueue*q, int val){
    if (isFull(q)){
        cout<<"the circularQueue is full"<<endl;
    }else {
        q->r = (q->r+1) % q->size;
        q->arr[q->r] = val;
        cout<<"the :" <<val<<" - added in the circular circularQueue"<<endl;
    }
}


int deQueue(struct circularQueue*q){
    int val = -1;
    if (isEmpty(q)){
        cout<<"the circularQueue is empty"<<endl;
    }else {
        q->f = (q->f+1) % q->size;
        val = q->arr[q->f];
        //cout<<"the :" <<val<<" - deque in the circular circularQueue"<<endl;
    }
    return val;
}

int main(){
    struct circularQueue *q = new circularQueue;
    q->size = 3;
    q->f = q->r = 0;
    q->arr = new int[q->size];

    enQueue(q, 77);
    enQueue(q, 18);

    // deQueue(q);
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    cout<<"dequeued the element:"<<deQueue(q)<<endl;
    // cout<<"dequeued the element:"<<deQueue(q)<<endl;

    
    enQueue(q, 4);
    enQueue(q, 5);

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




//agar hum variable ko value or(  q->arr[q->r] ) ke baad mein define karenge toh new value saamne aaygi
//else agar pehle define karenge toh value add ho jeyegi but jab hum return val karenge toh woh dequeue hoyi orighnal value show karega

//values overwriting
// #include <iostream>
// using namespace std;

// int main() {
//     int number = 5; // Initial value

//     cout << "Original value: " << number << endl;

//     // Overwriting the value
//     number = 10; 

//     cout << "New value: " << number << endl;

//     return 0;

// }

//orignal value = 5;
//new value = 10;
