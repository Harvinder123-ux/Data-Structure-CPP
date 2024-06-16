#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*next;
};

struct node*f = nullptr;
struct node*r = nullptr;

void linkListTraversal(struct node*ptr){
    cout<<"printiting the element of linked list"<<endl;
    while (ptr != nullptr){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}
void enqueue (int val){
    struct node*n = new node;
    //isme condition yeh hai ki agar hamari node == null hai toh hamara queue bhi full hai
    if(n == nullptr){//this condition is checking IsQueue is full
        cout<<"the queue is full"<<endl;
    }else{
        //nahito ek new node banne k baad humlog usme data add karenge
        n->data = val;
        //queue k last mein data add hota hai toh is scenario k hisaab se hum n->next null ptr kar denge
        n->next = nullptr;

        // lekin purane rear (r->next = n) ko new node k saath jodne se pehle hum yeh dekehenge ki hamare new node bhi front or rear ban jaye or yeh new node
        if(f== nullptr || r == nullptr){ //jab hum new element add karnge toh hum chahenge ki hamara front and rear bhi new node k equal hojaye
            f=r=n;
        }else {
            r->next = n;
            r=n;
            cout<<"the :" <<val<<" - added in the link list Queue"<<endl;
        }
    }
}

int dequeue(){
    int val =-1;
    //humne jaha par ek pointer banaya jo front ki jagah par aagya! or jaha par abb do nodes hai okk?
    struct node*ptr = f;
    if(f==nullptr){ //this condition is checking IsQueue Empty
       cout<<"the queue is empty"<<endl;
    }else {
       //isme hum ek node front waale ko aage bhej denge aur baad mein ek sirf pointer bachega starting mein
       f = f->next;

       //jiski value ko hum -1 kar denge;
        val = ptr->data;

       //aur baad mein hum pointer ko delete kar denge memory ko free karne k liye
       delete ptr;
       cout<<"the :" <<val<<" - deque in the link listQueue"<<endl;
    }
    return val;
}

int main(){
    

    linkListTraversal(f);

    dequeue();

    enqueue(17);
    enqueue(55);
    enqueue(34);

    // dequeue();

    linkListTraversal(f);




    return 0;

}