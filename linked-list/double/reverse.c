#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* reverse(struct node *head)
{
    struct node *temp = NULL;
    struct node *current = head;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    if(temp != NULL)
    {
        head = temp->prev;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;

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
        newNode->prev = NULL;
        if(head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    // Reverse
    head = reverse(head);
    // Display
    temp = head;
    printf("\nReversed Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}