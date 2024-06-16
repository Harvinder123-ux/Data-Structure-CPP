#include <iostream>
using namespace std;

struct queue {
    int size;
    int f;
    int r;
    int*arr;
};

int isEmpty(struct queue*q){
    while (q->f == q->r){
        return 1;
    }
    return 0;
}


bool isFull(struct queue*q){
    return (q->r == q->size-1);
}

void enqueue(struct queue*q, int val){
    if (isFull(q))
    {
       cout<<"cant insert! queue is full"<<endl;
    }else {
        q->r++;
        q->arr[q->r] = val;
        //cout<<"the element "<<val<<" inserted into the queue"<<endl;
    }
    
}


int dequeue(struct queue*q){
    int val = -1;
    if (isEmpty(q))
    {
       cout<<"cant insert! queue is empty"<<endl;
    }else {
        q->f++;
        val = q->arr[q->f];
      
       // cout<<"the element "<<val<<" dequeue from the queue"<<endl;
    }
    return val;
    
}

int main(){
     struct queue * q = new queue;
     q->size = 200;
     q->f= q->r = 0;
     q->arr = new int[q->size];

    //  BFS IMPLEMENTATION
     int node;
     int i = 0;
     //khaali array initalize kardiya
     int visited[7] = {0,0,0,0,0,0,0};

    //  //now abb - 7*7 ki ek adjency matrix banao - accordig to our bfs graph is solve kijiye
     int a [7] [7] = {
    //   0 1 2 3 4 5 6 
        {0,1,1,1,0,0,0},//0
        {1,0,1,0,0,0,0},//1
        {1,1,0,1,1,0,0},//2
        {1,0,1,0,1,0,0},//3
        {0,0,1,1,0,1,1},//4
        {0,0,0,0,1,0,0},//5
        {0,0,0,0,1,0,0} //6

     };

     
     cout<<i<<endl;
     visited[i] = 1;
     enqueue(q, i);//for exploration
     while (!isEmpty(q))
     { 
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {  //maanlo hum graph ke pehle array mein 0 ko explore kar rahe hain toh use=me dekh rahe hain ki kya hamar 0 connenceted bhi hai 1, 2, 3, se thats why a[node][j] == 1?
           if (a[node][j] == 1 && visited[j] == 0)
           {
            cout<<j<<endl;
            visited[j] = 1;
            //yeh baaki dusre nodes jo connected hain unhe explore karne k liye
            enqueue(q, j);

           }
           
        }
        
     }
  

    // if(isEmpty(q)){
    //     cout<<"The queue is empty"<<endl;
    // }
    
    // if(isFull(q)){
    //     cout<<"The queue is Full"<<endl;
    // }

    // delete[] q->arr; // Don't forget to free the memory allocated for the array
    // delete q; // Don't forget to free the memory allocated for the queue structure


    return 0;
}