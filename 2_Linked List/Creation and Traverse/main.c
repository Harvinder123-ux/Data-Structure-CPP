#include <stdio.h>


struct node
{
    int data;
    struct Node* next;
};

int main(){

    struct Node*head;
    struct Node*second;
    struct Node*third;

    //allocate node for link list in heap
    head = (struct Node*)malloc(sizeof(struct node));
    second = (struct Node*)malloc(sizeof(struct node));
    third = (struct Node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 11;
    third->next = null;


    return 0;
}