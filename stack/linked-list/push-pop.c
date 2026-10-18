
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int value)
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct node *temp;

    if (top == NULL){
        printf("Stack Underflow\n");
    }
    else{
        temp = top;
        printf("Deleted: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    pop();

    return 0;
}
