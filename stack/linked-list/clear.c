
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int value)
{
    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void clear()
{
    struct node *temp;

    while (top != NULL){
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("Stack cleared\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    clear();

    if (top == NULL)
        printf("Stack is empty\n");

    return 0;
}
