
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
        return;
    // rear++;
    // queue[rear] = value; 
    queue[++rear] = value;
}

void dequeue()
{
    if (rear == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted: %d\n", queue[front]);

        if (front == rear){
            front = 0;
            rear = -1;
        }
        else{
            front++;
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    return 0;
}
