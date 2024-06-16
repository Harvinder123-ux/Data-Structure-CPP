#include <iostream>
#include <cstring>
using namespace std;

struct stack {
    int size;
    int top;
    char*arr;
};

bool isEmpty (struct stack*sp){
    return (sp->top == -1);
}


bool isFull (struct stack*sp){
    return (sp->top == sp->size -1);
}

void push(struct stack*sp, char val){
    if(isFull(sp)){
      cout<<"cant push the stack is full"<<endl;
    }else {
        sp->top++;
        sp->arr[sp->top] = val;
        
    }
}


char pop(struct stack*sp){
    if(isEmpty(sp)){
        return -1;
    }else {
        char val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

char stackTop(struct stack * sp){
    return sp->arr[sp->top+1];
}


int isPrec (char ch){
    if (ch == '*' || ch == '/'){
        return 3;
    }
    if (ch == '+' || ch == '-'){
        return 1;
    }
  
}


int isOperator(char ch){
    if ( ch == '+' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;

    }else {
        return 0;
    }
}


char* infixToPostfix(char*infix){
    struct stack * sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    // Determine the length of the infix expression
    char infixLength = strlen(infix);
    // Allocate memory for the postfix array
    char* postfix = new char[infixLength + 1]; // +1 for null terminator


    int i = 0; //in-fix scanner
    int j = 0; //postfix fill addition

    while(infix[i] != '\0'){
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
            // push(sp, infix[i]);
        }else{
             if(isPrec(infix[i])>=isPrec(stackTop(sp))){
            // if(isEmpty(sp) && isPrec(infix[i]) >=  isPrec(stackTop(sp))){
                push(sp, infix[i]);
                i++;
                 
            }else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
    postfix[j] = pop(sp);
       j++;
    }
    postfix[j] = '\0';
    return postfix;

};

int main (){
    // Your infix expression
    char *infix = "(m-n)*(p+q)";

    char* postfix = infixToPostfix(infix);
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;
   
    return 0;

}



// #include <iostream>
// #include <cstring>
// using namespace std;

// struct stack {
//     int size;
//     int top;
//     char*arr;
// };

// bool isEmpty (struct stack*sp){
//     return (sp->top == -1);
// }


// bool isFull (struct stack*sp){
//     return (sp->top == sp->size -1);
// }

// void push(struct stack*sp, char val){
//     if(isFull(sp)){
//       cout<<"cant push the stack is full"<<endl;
//     }else {
//         sp->top++;
//         sp->arr[sp->top] = val;
        
//     }
// }


// char pop(struct stack*sp){
//     if(isEmpty(sp)){
//         return -1;
//     }else {
//         char val = sp->arr[sp->top];
//         sp->top--;
//         return val;
//     }
// }

// char stackTop(struct stack * sp){
//     return sp->arr[sp->top+1];
// }


// int Precedence (char ch){
//     //  if (ch == '*' || ch == '/'){
//     //     return 3;
//     // }
//     // if (ch == '+' || ch == '-'){
//     //     return 1;
//     // }
//     if (ch == '+' || ch == '-') {
//         return 1;
//     } else if (ch == '*' || ch == '/') {
//         return 2;
//     }
//     return 0;
   
// }


// int isOperator(char ch){
//     if ( ch == '+' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
//         return 1;

//     }else {
//         return 0;
//     }
// }


// char* infixToPostfix(char*infix){
//     struct stack * sp = new stack;
//     sp->size = 100;
//     sp->top = -1;
//     sp->arr = new char[sp->size];
//     // Determine the length of the infix expression
//     char infixLength = strlen(infix);
//     // Allocate memory for the postfix array
//     char* postfix = new char[infixLength + 1]; // +1 for null terminator


//     int i = 0; //in-fix scanner
//     int j = 0; //postfix fill addition

//     while(infix[i] != '\0'){
//         if (!isOperator(infix[i])){
//             postfix[j] = infix[i];
//             i++;
//             j++;
//             // push(sp, infix[i]);
//         }else{
//              if(Precedence(infix[i])>=Precedence(stackTop(sp))){
//             // if(isEmpty(sp) && isPrec(infix[i]) >=  isPrec(stackTop(sp))){
//                 push(sp, infix[i]);
//                 i++;
                 
//             }else {
//                 postfix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }

//     while (!isEmpty(sp))
//     {
//     postfix[j] = pop(sp);
//        j++;
//     }
//     postfix[j] = '\0';
//     return postfix;

// };

// int main (){
//     // Your infix expression
//     char *infix = "a+b*t/6";

//     char* postfix = infixToPostfix(infix);
//     cout << "Infix Expression: " << infix << endl;
//     cout << "Postfix Expression: " << postfix << endl;
   
//     return 0;

// }