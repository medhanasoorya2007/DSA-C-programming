#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;
    struct node *current = NULL;
    struct node *runner = NULL;
    struct node *delNode = NULL;

    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++)
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
    // Remove duplicates
    current = head;
    while(current != NULL)
    {
        runner = current;
        while(runner->next != NULL)
        {
            if(current->data == runner->next->data)
            {
                delNode = runner->next;
                runner->next = delNode->next;
                free(delNode);
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    // Display
    temp = head;
    printf("\nAfter removing duplicates: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    return 0;
}