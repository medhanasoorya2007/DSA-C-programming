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

/* Infix to Postfix  (e.g. a+b*c  ->  abc*+) */
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
 
void infixToPostfix(char infix[], char postfix[]) {
    top = -1;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;                  // operand -> straight to output
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && stack[top] != '(')
                postfix[k++] = pop();
            pop();                             // throw away '('
        } else {                               // operator
            while (!isEmpty() && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty()) {
        postfix[k++] = pop();   // empty the stack
    }   
    postfix[k] = '\0';
}

int main() {

    printf("\n=== 5. Infix to Postfix ===\n");
    char post[MAX];
    infixToPostfix("a+b*(c-d)", post);
    printf("a+b*(c-d) -> %s\n", post);
 
    return 0;
}
 