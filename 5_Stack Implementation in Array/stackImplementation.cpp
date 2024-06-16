#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};
    //instead of using ptr u can also use s or any keyword bcoz s/ptr in this rely from this    struct stack *s;  s->top = -1;  s->size = 80;
     bool isEmpty(struct stack* ptr ){
        if (ptr->top == -1){
            return true;
        }else {
            return false;
        }
    
    };
    bool isFull(struct stack* ptr ){
        if (ptr->top == ptr->size-1){
            return true;
        } else {
            return false;
        }
    
    }


int main (){

    //in this s is stack - jaha par s pehle stack thi jisme hum dot pointer use kar sakte hai
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = new int[s.size];


    // in the use of * now s is pointer tha dynimicially acllocate memory in heap
    struct stack *s;
    s->size = 3;
    s->top = -1;
    s->arr = new int[s->size];

    //push the element
    s->arr[0] = 4;
    s->top++;

    s->arr[1] = 6;
    s->top++;

    s->arr[2] = 12;
    s->top++;
    
    if (isEmpty(s)) {
        // Perform actions when the stack is empty
         cout<<"the stack is empty! you can push"<<endl;
    } else {
        // Perform actions when the stack is not empty
        cout << "Performing actions when the stack is not empty." << endl;
    }

     if (isFull(s)) {
        // Perform actions when the stack is empty
        cout<<"the stack is full! you can't push Now";
    } else {
        // Perform actions when the stack is not empty
        cout << "Performing actions when the stack is not Full." << endl;
    }

  return 0;
}