#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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
    // Make the list circular
    temp->next = head;
    // Display
    temp = head;
    if(head != NULL)
    {
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        while(temp != head);
        printf("HEAD");
    }
    return 0;
}