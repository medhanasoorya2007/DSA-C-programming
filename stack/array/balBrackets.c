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

/* 2. Balanced parentheses  ( ) { } [ ] */
int isBalanced(char s[]) {
    top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } 
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty()) return 0;
            
            // Pop once safely, then verify the match
            char open = pop();
            if ((s[i] == ')' && open != '(') ||
                (s[i] == '}' && open != '{') ||
                (s[i] == ']' && open != '[')) {
                return 0;
            }
        }
    }
    return isEmpty();
}

int main() {
    top = -1;
    push(10); push(20); push(30);
    
 
    printf("\n=== 2. Balanced parentheses ===\n");
    printf("{[()]} -> %s\n", isBalanced("{[()]}") ? "Balanced" : "Not balanced");
    printf("{[(])} -> %s\n", isBalanced("{[(])}") ? "Balanced" : "Not balanced");
 
    return 0;
}
 