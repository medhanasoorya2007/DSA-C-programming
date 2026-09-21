#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void sort(struct node *head)
{
    struct node *current;
    struct node *runner;

    int temp;

    current = head;

    while(current != NULL)
    {
        runner = current->next;
        while(runner != NULL)
        {
            if(current->data > runner->data)
            {
                temp = current->data;
                current->data = runner->data;
                runner->data = temp;
            }
            runner = runner->next;
        }
        current = current->next;
    }
}

int main()
{
    int n, value;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Before sorting: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    sort(head);
    printf("\nAfter sorting: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}