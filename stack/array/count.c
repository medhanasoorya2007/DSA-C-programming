
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int size()
{
    return top + 1;
}

int main()
{
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    printf("Number of elements: %d\n", size());

    return 0;
}
