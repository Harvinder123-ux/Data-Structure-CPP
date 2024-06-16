#include <iostream>
using namespace std;
struct stack {
    int size;
    int top;
    char *arr;
};

// int stackTraverse(struct stack *s, int top){
//     for (int i = 0; i < top-1; i++)
//     {
       
//     }
    

// }

bool isEmpty(struct stack*sp){
    return (sp->top == -1);
}


bool isFull(struct stack*sp){
    return (sp->top == sp->size == -1);
}

void push(struct stack *sp, char val){
    if(isFull(sp)){
     cout<<"the stack is full";
    }else {
        sp->top++;
        sp->arr[sp->top] = val;
        // cout <<"element pushed in stack :" <<val<<endl;
    }
}


char pop(struct stack *sp){
    if(isEmpty(sp)){
     cout<<"the stack is Underflow";
    }else {
        char val = sp->arr[sp->top];
        sp->top--;
        // cout <<"element pushed in stack"<<endl;
        return '\0'; // Return a default value to indicate failure
        return val;
    }
}

int parenthesisMatch(char*exp){
    struct stack*sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char [sp->size];
    
    for (int i = 0; i < exp[i]!='\0'; i++)
    {
        if(exp[i] == '('){
            push (sp, '(');

        }else if
            (exp[i] == ')'){
                if (isEmpty(sp)){ ///stack pop karne se pehle hi empty hai toh invalid balandce
                    // cout<<"invalid balanced";

                }else{
                    pop(sp);
                    // cout<<"parenthesis balanced"<<endl;

                }
                
            }
        }


        if(isEmpty(sp)){
        cout<<"parenthesis expression is balanced"<<endl;
        }else {
          cout<<"parenthesis is not balanced"<<endl;
        }
    };
    
int main(){
    // struct stack *s;
    // s->size = 26;
    // s->top = -1;
    // s->arr = new char[s->size];
    

    // //push the element
    // s->arr[0] = 3;
    // s->top++;

    // s->arr[1] = 7;
    // s->top++;

    // s->arr[2] = 3;
    // s->top++;

    // s->arr[3] = 6;
    // s->top++;

    // s->arr[4] = 9;
    // s->top++;
    
    // push(s, 55);
    // push(s, 4);
    // pop(s);
    char expression[] = "((a+b)*(c-d)";
    parenthesisMatch(expression);

    return 0;



  
}