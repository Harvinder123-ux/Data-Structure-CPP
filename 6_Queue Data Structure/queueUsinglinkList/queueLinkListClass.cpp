#include <iostream>
using namespace std;

class linkListQueue {
    public:
    struct node {
        int data;
        struct node*next;
    };

    public:
    struct node*f = nullptr;
    struct node*r = nullptr;
    
    bool isEmpty(){
        // if(f==nullptr){
        //     cout<<"the queue is Full"<<endl;
        // }
        return f==nullptr;

    }

    void enqueue(int val){
        struct node*n = new node;
        if (n == nullptr){
            //this say new node nahi ban sakti kyunk queeueue is full
            cout<<"the queue is full";
        }else {
            n->data = val;
            n->next = nullptr;

            if(f==nullptr || r==nullptr){
                f=r=n;
            }else {
                r->next = n;
                r=n;
            }
            

        }
    }

    int deQueue (){
        struct node *ptr = f;
        int val = -1;
        if(isEmpty()){
            cout<<"the queueu is empty"<<endl;
        }else {
            f = f->next;
            val = ptr->data;
            delete ptr;
        }
        return val;
    }


    void linkedTraversal (){
        struct node*ptr = f;
        while(ptr != nullptr){
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }
    
};

int main(){
    linkListQueue queue;
    queue.enqueue(17);
    queue.enqueue(7);
    queue.linkedTraversal();


    return 0;

}