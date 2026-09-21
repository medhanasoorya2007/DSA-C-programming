#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp = NULL;
    struct node *newNode = NULL, *delNode = NULL;

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
        printf("\n1. Delete from Front");
        printf("\n2. Delete from End");
        printf("\n3. Delete from Position");
        printf("\n4. Delete by Value");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // DELETE FROM FRONT
        if(choice == 1)
        {
            if(head == NULL)
            {
                printf("List is empty!");
            }
            else if(head->next == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                temp = head;

                while(temp->next != head)
                {
                    temp = temp->next;
                }
                delNode = head;
                head = head->next;
                temp->next = head;

                free(delNode);
            }
        }
        // DELETE FROM END
        else if(choice == 2)
        {
            if(head == NULL)
            {
                printf("List is empty!");
            }
            else if(head->next == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                temp = head;

                while(temp->next->next != head)
                {
                    temp = temp->next;
                }

                delNode = temp->next;
                temp->next = head;

                free(delNode);
            }
        }
        // DELETE FROM POSITION
        else if(choice == 3)
        {
            printf("Enter position: ");
            scanf("%d", &pos);

            if(head == NULL)
            {
                printf("List is empty!");
            }
            else if(pos == 1)
            {
                if(head->next == head)
                {
                    free(head);
                    head = NULL;
                }
                else
                {
                    temp = head;
                    while(temp->next != head)
                    {
                        temp = temp->next;
                    }
                    delNode = head;
                    head = head->next;
                    temp->next = head;

                    free(delNode);
                }
            }
            else
            {
                temp = head;
                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                delNode = temp->next;

                if(delNode == head)
                {
                    printf("Invalid position!");
                }
                else
                {
                    temp->next = delNode->next;
                    free(delNode);
                }
            }
        }
        // DELETE BY VALUE
        else if(choice == 4)
        {
            printf("Enter value: ");
            scanf("%d", &value);

            if(head == NULL)
            {
                printf("List is empty!");
            }
            else if(head->data == value)
            {
                if(head->next == head)
                {
                    free(head);
                    head = NULL;
                }
                else
                {
                    temp = head;
                    while(temp->next != head)
                    {
                        temp = temp->next;
                    }
                    delNode = head;
                    head = head->next;
                    temp->next = head;

                    free(delNode);
                }
            }
            else
            {
                temp = head;
                while(temp->next != head &&
                      temp->next->data != value)
                {
                    temp = temp->next;
                }

                if(temp->next == head)
                {
                    printf("Element not found!");
                }
                else
                {
                    delNode = temp->next;
                    temp->next = delNode->next;

                    free(delNode);
                }
            }
        }
        // DISPLAY
        else if(choice == 5)
        {
            if(head == NULL)
            {
                printf("List is empty!");
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
        else if(choice == 6)
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