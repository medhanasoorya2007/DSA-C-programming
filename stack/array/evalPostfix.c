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
    stack[++top] = x;  
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = stack[top--]; 
    return x;
}

/* 6. Postfix evaluation (single-digit numbers, e.g. "23*54*+9-") */
int evaluatePostfix(char exp[]) {
    top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isdigit(c)) {
            push(c - '0');                     // char -> number
        } else {
            int b = pop();                     // second operand comes out first
            int a = pop();
            if (c == '+') push(a + b);
            else if (c == '-') push(a - b);
            else if (c == '*') push(a * b);
            else if (c == '/') push(a / b);
        }
    }
    return pop();
}

int main() {
    top = -1;
    push(10); push(20); push(30);
    
 
    printf("\n=== 6. Postfix evaluation ===\n");
    printf("23*54*+9- = %d\n", evaluatePostfix("23*54*+9-"));
 
    return 0;
}
 