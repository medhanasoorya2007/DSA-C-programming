#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;

    int n, value, choice, pos;

    // Create initial circular linked list
    printf("Enter number of elements: ");
    scanf("%d", &n);

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

    // Make the list circular
    if(head != NULL)
    {
        temp->next = head;
    }

    // Menu
    while(1)
    {
        printf("\n\n--- MENU ---");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // INSERT AT FRONT
        if(choice == 1)
        {
            printf("Enter element: ");
            scanf("%d", &value);

            newNode = malloc(sizeof(struct node));

            newNode->data = value;

            if(head == NULL)
            {
                head = newNode;
                newNode->next = head;
            }
            else
            {
                temp = head;
                while(temp->next != head)
                {
                    temp = temp->next;
                }
                newNode->next = head;
                temp->next = newNode;
                head = newNode;
            }
        }

        // INSERT AT END
        else if(choice == 2)
        {
            printf("Enter element: ");
            scanf("%d", &value);

            newNode = malloc(sizeof(struct node));

            newNode->data = value;

            if(head == NULL)
            {
                head = newNode;
                newNode->next = head;
            }
            else
            {
                temp = head;
                while(temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
            }
        }

        // INSERT AT POSITION
        else if(choice == 3)
        {
            printf("Enter position: ");
            scanf("%d", &pos);

            printf("Enter element: ");
            scanf("%d", &value);

            newNode = malloc(sizeof(struct node));

            newNode->data = value;

            if(pos == 1)
            {
                if(head == NULL)
                {
                    head = newNode;
                    newNode->next = head;
                }
                else
                {
                    temp = head;
                    while(temp->next != head)
                    {
                        temp = temp->next;
                    }
                    newNode->next = head;
                    temp->next = newNode;
                    head = newNode;
                }
            }
            else
            {
                temp = head;
                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        // DISPLAY
        else if(choice == 4)
        {
            if(head == NULL)
            {
                printf("\nLinked List is empty!");
            }
            else
            {
                temp = head;
                printf("\nCircular Linked List: ");
                do
                {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }
                while(temp != head);
                printf("HEAD\n");
            }
        }
        // EXIT
        else if(choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice!");
        }
    }
    return 0;
}