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

/*  Decimal to binary */
void decimalToBinary(int n) {
    top = -1;
    if (n == 0) { 
        printf("0\n"); 
        return; 
    }
    while (n > 0) {
        push(n % 2);                           // remainders go in
        n = n / 2;
    }
    while (!isEmpty()) {
        printf("%d", pop());        // come out reversed = correct
    }
    printf("\n");
}
 
/*  Palindrome check */
int isPalindrome(char s[]) {
    top = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        push(s[i]);
    }
    for (int i = 0; i < len; i++){
        if (s[i] != pop()) 
            return 0;
    }
    return 1;
}

int main() {
    top = -1;
    push(10); push(20); push(30);
    printf("\n=== Decimal to binary ===\n");
    printf("13 -> ");
    decimalToBinary(13);
 
    printf("\n=== Palindrome ===\n");
    printf("madam -> %s\n", isPalindrome("madam") ? "Yes" : "No");
    return 0;
}
 
