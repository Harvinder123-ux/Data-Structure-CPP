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

int pop(struct stack *sp)
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

int parenthesis(char *exp)
{
    struct stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                cout << "unbalance expression";
            }
            else
            {
                pop(sp);
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
    char expression[] = "((a+b)*(c-d))";
    parenthesis(expression);

    return 0;
}
