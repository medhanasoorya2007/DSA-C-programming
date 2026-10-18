
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Deleted: %d\n", stack[top]);
        top--;
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
