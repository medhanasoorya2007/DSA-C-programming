
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

void display()
{
    struct node *temp;

    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Stack elements (top to bottom):\n");
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    return 0;
}
