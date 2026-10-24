/* ============================================================
   STACK USING LINKED LIST  (LIFO)
   Part 1 : The TEMPLATE  (memorize this!)
   Part 2 : Applications  (same problems, same logic as array)
   Advantage over array: no size limit, no "full" check.
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;   // NULL means the stack is empty

int isEmpty() { return top == NULL; }

void push(int x) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {                 // malloc failed = no memory
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = x;     // 1. fill the new node
    newNode->next = top;   // 2. point it to the old top
    top = newNode;         // 3. new node becomes the top
}

int pop() {
    struct Node *temp = top;   // 1. remember the top node

    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = temp->data;        // 2. take its value
    top = top->next;           // 3. move top down
    free(temp);                // 4. delete the old node
    return x;
}

void reverseStack() {
    struct Node *prev = NULL, *curr = top, *next = NULL;
    while (curr != NULL) {
        next = curr->next;   // save next
        curr->next = prev;   // flip the arrow
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }
    top = prev;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack (top -> bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------------- MAIN: test everything ---------------- */
int main() {
    printf("=== Basic operations ===\n");
    push(10); push(20); push(30);
    display();

    return 0;
}
