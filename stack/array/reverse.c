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

void reverseString(char s[]) {
    top = -1;                                  // always reset first
    for (int i = 0; s[i] != '\0'; i++){
        push(s[i]);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = pop();
    }
}

void reverseStack() {
    int temp[MAX], n = 0;
    while (!isEmpty()) {
        temp[n++] = pop();
    }      // empty into temp
    for (int i = 0; i < n; i++) {
        push(temp[i]);
    } // push back in same order
}

int main() {
    top = -1;
    push(10); push(20); push(30);
    
 
    printf("\n=== 1. Reverse string ===\n");
    char s1[] = "hello";
    reverseString(s1);
    printf("%s\n", s1);
 
    return 0;
}
 