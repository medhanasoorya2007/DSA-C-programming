/* ============================================================
   QUEUE USING LINKED LIST  (FIFO)
   Two pointers: front (remove here) and rear (add here)
   No size limit, no wrap-around needed.
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>

/* ---------------- PART 1: THE TEMPLATE ---------------- */
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() { return front == NULL; }

void enqueue(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = x;           // 1. fill the node
    newNode->next = NULL;        // 2. it will be last, so points to NULL
    if (rear == NULL) {          // 3a. queue was empty
        front = rear = newNode;
    } else {                     // 3b. link after the old rear
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node *temp = front;   // 1. remember front
    int x = temp->data;          // 2. take value
    front = front->next;         // 3. move front
    if (front == NULL)           // 4. queue became empty
        rear = NULL;             //    (don't forget this line!)
    free(temp);                  // 5. delete old node
    return x;
}

int peek() {
    if (isEmpty()) { printf("Queue is empty\n"); return -1; }
    return front->data;
}

int size() {
    int count = 0;
    for (struct Node *t = front; t != NULL; t = t->next) count++;
    return count;
}

void display() {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Queue (front -> rear): ");
    for (struct Node *t = front; t != NULL; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

void clear() {
    while (!isEmpty()) dequeue();
}

/* ---------------- PART 2: APPLICATIONS ---------------- */
/* Same logic as the circular version: just call clear() first. */

void generateBinary(int n) {
    clear();
    enqueue(1);
    for (int i = 0; i < n; i++) {
        int x = dequeue();
        printf("%d ", x);
        enqueue(x * 10);
        enqueue(x * 10 + 1);
    }
    printf("\n");
    clear();
}

void reverseQueue() {
    if (isEmpty()) return;
    int x = dequeue();
    reverseQueue();
    enqueue(x);
}

int josephus(int n, int k) {
    clear();
    for (int i = 1; i <= n; i++) enqueue(i);
    while (size() > 1) {
        for (int i = 1; i < k; i++) enqueue(dequeue());
        dequeue();
    }
    return dequeue();
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    printf("Front: %d, Size: %d\n", peek(), size());

    clear();
    printf("\nBinary 1 to 5: ");
    generateBinary(5);

    for (int i = 1; i <= 5; i++) enqueue(i);
    reverseQueue();
    printf("Reversed: ");
    display();

    printf("Josephus(5,2) survivor: %d\n", josephus(5, 2));
    clear();
    return 0;
}