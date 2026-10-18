
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void change(int index, int value)
{
    if (index < 0 || index > top){
        printf("Invalid index\n");
    }
    else{
        stack[index] = value;
        printf("Element updated\n");
    }
}

int main()
{
    int i;

    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    printf("Enter index and new value: ");
    scanf("%d %d", &i, &stack[0]); 
    return 0;
}
