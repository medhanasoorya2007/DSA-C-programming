/* ============================================================
   SIMPLE QUEUE USING ARRAY  (FIFO - First In, First Out)
   Learn this FIRST to understand the idea.
   Weakness: space at the front is never reused (see demo in main).
   For real problems use queue_circular.c
   ============================================================ */
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0;     // index of the first element
int rear = -1;     // index of the last element

int isEmpty() { return front > rear; }
int isFull()  { return rear == MAX - 1; }
int size()    { return isEmpty() ? 0 : rear - front + 1; }

void enqueue(int x) {            // add at the REAR
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    rear++;                      // 1. move rear
    queue[rear] = x;             // 2. store
    //queue[++rear] = x;            3. alternative: combine the two steps
}

int dequeue() {                  // remove from the FRONT
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = queue[front];        // 1. take value
    front++;                     // 2. move front
    //int x = queue[front++];       3. alternative: combine the two steps
    return x;
}

int peek() {                     // look at the front
    if (isEmpty()) {
        printf("Queue is empty\n"); 
        return -1; 
    }
    return queue[front];
}

int rearValue() {                // look at the rear
    if (isEmpty()) { 
        printf("Queue is empty\n"); 
        return -1; 
    }
    return queue[rear];
}

void display() {
    if (isEmpty()) { 
        printf("Queue is empty\n"); 
        return; 
    }
    printf("Queue (front -> rear): ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    printf("Front: %d, Rear: %d, Size: %d\n", peek(), rearValue(), size());
    display();

    printf("\n--- The weakness of the simple queue ---\n");
    enqueue(40); enqueue(50);          // rear reaches MAX-1
    dequeue(); dequeue();              // two empty slots at the front
    printf("Size is %d of %d, but: ", size(), MAX);
    enqueue(60);                       // still says Overflow!
    return 0;
}