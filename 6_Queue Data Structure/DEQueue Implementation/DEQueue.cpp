// #include <iostream>
// using namespace std;

// struct DEQueue {
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// void enQueueR(struct DEQueue *q, int val){
//     if (q->r == q->size-1){
//         cout<<"the queue is full";
//     }else {
//         q->r = q->r+1;
//         q->arr[q->r] = val;
//         cout<<"the  :" <<val<<" - Enqueued from the Rear of the queue"<<endl;
//     }
// }


// void enQueuef(struct DEQueue *q, int val){
//     if (q->f == 1){
//         cout<<"the queuce is full";
//     }else {
//         q->f = q->f-1;
//         q->arr[q->f] = val;
//         cout<<"the  :" <<val<<" - Enqueued from the front of the queue"<<endl;
//     }
// }

// int deQueuef(struct DEQueue *q){
//     int val = -1;
//     if (q->f == q->r){
//         cout<<"the queue is Empty";
//     }else {
//         q->f++;
//         val = q->arr[q->f];
//         cout<<"the  :" <<val<<" - dequeued from the Front of the queue"<<endl;

//     }
//     return val; 
// }


// int deQueueR(struct DEQueue *q){
//     int val = -1;
//     //q->r == -1
//     if (q->r == -1 || q->r < q->f){
//         cout<<"the queue is Empty";
//     }else {
//         val = q->arr[q->r];
//         q->r--;
//         cout<<"the  :" <<val<<" - dequeued from the Rear of the queue"<<endl;

//     }

//     return val;
// }

// int main(){
//     struct DEQueue *q = new DEQueue;
//     q->size = 10;
//     q->f = q->r = -1;
//     q->arr = new int [q->size];

//     // Perform operations
//     enQueueR(q, 17);
//     enQueueR(q, 5);
//     enQueueR(q, 19);

//     enQueuef(q, 9);
//     enQueuef(q, 6);
//     enQueuef(q, 15);

//     deQueueR(q);
//     deQueuef(q);
//     deQueuef(q);
//     deQueuef(q);
//     deQueuef(q);

//     delete[] q->arr; // Don't forget to free the memory allocated for the array
//     delete q; // Don't forget to free the memory allocated for the queue structure


//     return 0;
// }


// chat gpt not working
// #include <iostream>
// using namespace std;

// struct DEQueue {
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// void enQueueR(struct DEQueue *q, int val) {
//     if (q->r == q->size - 1) {
//         cout << "the queue is full" << endl;
//     } else {
//         q->r = q->r + 1;
//         q->arr[q->r] = val;
//         cout << "the  :" << val << " - Enqueued from the Rear of the queue" << endl;
//     }
// }

// void enQueuef(struct DEQueue *q, int val) {
//     if (q->f != 0) {
//         q->f = q->f - 1;
//         q->arr[q->f] = val;
//         cout << "the  :" << val << " - Enqueued from the front of the queue" << endl;
//     } else {
//         cout << "the queue is full (enqueue from the front)" << endl;
//     }
// }

// int deQueuef(struct DEQueue *q) {
//     int val = -1;
//     if (q->f == -1 || q->f > q->r) {
//         cout << "the queue is Empty" << endl;
//     } else {
//         val = q->arr[q->f];
//         q->f++;
//         cout << "the  :" << val << " - dequeued from the Front of the queue" << endl;
//     }
//     return val;
// }

// int deQueueR(struct DEQueue *q) {
//     int val = -1;
//     if (q->f > q->r) {
//         cout << "the queue is Empty" << endl;
//     } else {
//         val = q->arr[q->r];
//         q->r--;
//         cout << "the  :" << val << " - dequeued from the Rear of the queue" << endl;
//     }

//     return val;
// }

// int main() {
//     struct DEQueue *q = new DEQueue;
//     q->size = 10;
//     q->f = q->r = -1;
//     q->arr = new int[q->size];

//     // Perform operations
//     enQueueR(q, 17);
//     enQueueR(q, 5);
//     enQueueR(q, 19);

//     enQueuef(q, 9);
//     enQueuef(q, 6);
//     enQueuef(q, 15);

//     deQueueR(q);
//     deQueuef(q);
//     deQueuef(q);
//     deQueuef(q);
//     deQueuef(q);

//     delete[] q->arr; // Don't forget to free the memory allocated for the array
//     delete q; // Don't forget to free the memory allocated for the queue structure

//     return 0;
// }
