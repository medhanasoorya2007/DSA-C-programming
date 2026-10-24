/* ============================================================
   STACK MASTER FILE  (LIFO - Last In, First Out)
   Part 1 : The TEMPLATE  (memorize this!)
   note: create your own stack implementation by changing the data type of the stack array and the function parameters
   ============================================================ */
   
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];   // the box that stores data
int top = -1;     // -1 means the stack is empty

int isEmpty() { return top == -1; }
int isFull()  { return top == MAX - 1; }
int size()    { return top + 1; }

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    top++;              // 1. move top up
    stack[top] = x;     // 2. put value there
    //stack[++top] = x;  3.alternative: combine the two steps
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = stack[top];     // 1. take value
    top--;                  // 2. move top down
    // int x = stack[top--];  3.alternative: combine the two steps
    return x;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    printf("=== Basic operations ===\n");
    top = -1;
    push(10); push(20); push(30);
    display();
    printf("Popped: %d\n", pop());
    printf("Peek: %d\n", peek());
    printf("Size: %d\n", size());
}