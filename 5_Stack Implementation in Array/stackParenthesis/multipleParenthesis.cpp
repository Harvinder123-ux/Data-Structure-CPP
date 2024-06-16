#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
};

bool isEmpty(struct stack *sp)
{
    return (sp->top == -1);
}

bool isFull(struct stack *sp)
{
    return (sp->top == sp->size - 1);
}

void push(struct stack *sp, char val)
{
    if (isFull(sp))
    {
        cout << "the stack is overflow" << endl;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = val;
        // cout <<"the element pushed in stack"<<endl;
    }
}


char pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        cout << "the stack is underflow" << endl;
    }
    else
    {

        char val = sp->arr[sp->top];
        sp->top--;
        return val;
        // cout <<"the element pushed in stack"<<endl;
    }
}

char stackTop (struct stack*sp){
    return sp->arr[sp->top+1];
}

bool match(char a, char b){
//if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
//     {
//         cout << "match" << endl;
//         return true;
//     }
    if(a == '{' && b== '}' ){
       return true;
    }else if(a == '[' && b== ']' ){
         return true;
    }else if(a == '(' && b== ')'){
         return true;
    }
     return false;


}



int parenthesis(char *exp)
{
    struct stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
          
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                cout << "unbalance expression"<<endl;
            }
            else
            {
                char popMatch = pop(sp);
                if(!match(popMatch, exp[i])){
                   cout<<" keep checking"<<endl;
                }
            }
        }
    }
    if (isEmpty(sp))
    {
        cout << "the expression is balanced" << endl;
    }
    else
    {
        cout << "the expression is not balanced" << endl;
    }

    // delete[] sp->arr;
    // delete sp;
}

int main()
{
    char expression[] = "{([a+b]*[c-d])}";
    parenthesis(expression);

    return 0;
}




//chat gpt code
// #include <iostream>
// using namespace std;

// struct stack
// {
//     int size;
//     int top;
//     char *arr;
// };

// bool isEmpty(struct stack *sp)
// {
//     return (sp->top == -1);
// }

// bool isFull(struct stack *sp)
// {
//     return (sp->top == sp->size - 1);
// }

// void push(struct stack *sp, char val)
// {
//     if (isFull(sp))
//     {
//         cout << "the stack is overflow" << endl;
//     }
//     else
//     {
//         sp->top++;
//         sp->arr[sp->top] = val;
//     }
// }

// char pop(struct stack *sp)
// {
//     if (isEmpty(sp))
//     {
//         cout << "the stack is underflow" << endl;
//         return '\0';
//     }
//     else
//     {
//         char val = sp->arr[sp->top];
//         sp->top--;
//         return val;
//     }
// }

// char stackTop(struct stack *sp)
// {
//     return sp->arr[sp->top];
// }

// bool match(char a, char b)
// {
//     if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
//     {
//         cout << "match" << endl;
//         return true;
//     }
//     else
//     {
//         cout << "not matched" << endl;
//         return false;
//     }
// }

// int parenthesis(char *exp)
// {
//     struct stack *sp = new stack;
//     sp->size = 100;
//     sp->top = -1;
//     sp->arr = new char[sp->size];
//     for (int i = 0; exp[i] != '\0'; i++)
//     {
//         if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
//         {
//             push(sp, exp[i]);
//         }
//         else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
//         {
//             if (isEmpty(sp))
//             {
//                 cout << "unbalanced expression" << endl;
//             }
//             else
//             {
//                 char popMatch = pop(sp);
//                 if (!match(popMatch, exp[i]))
//                 {
//                     cout << "keep checking" << endl;
//                 }
//                 else
//                 {
//                     cout << "not balanced" << endl;
//                 }
//             }
//         }
//     }
//     if (isEmpty(sp))
//     {
//         cout << "the expression is balanced" << endl;
//     }
//     else
//     {
//         cout << "the expression is not balanced" << endl;
//     }

//     delete[] sp->arr;
//     delete sp;
// }

// int main()
// {
//     char expression[] = "{([a+b]*[c-d])}";
//     parenthesis(expression);

//     return 0;
// }
