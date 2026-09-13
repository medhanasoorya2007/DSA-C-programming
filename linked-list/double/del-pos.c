#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp = NULL;
    struct node *newNode = NULL, *delNode = NULL;

    int n, value, choice, pos;

    // Create initial linked list
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

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

    // Menu
    while(1)
    {
        printf("\n\n--- DELETION MENU ---");
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
            else
            {
                delNode = head;
                head = head->next;
                if(head != NULL)
                {
                    head->prev = NULL;
                }
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
            else
            {
                temp = head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                delNode = temp;

                if(temp->prev != NULL)
                {
                    temp->prev->next = NULL;
                }
                else
                {
                    head = NULL;
                }
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
                delNode = head;
                head = head->next;

                if(head != NULL)
                {
                    head->prev = NULL;
                }
                free(delNode);
            }
            else
            {
                temp = head;
                for(int i = 1; i < pos; i++)
                {
                    temp = temp->next;
                }

                delNode = temp;
                temp->prev->next = temp->next;

                if(temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                free(delNode);
            }
        }
        // DELETE BY VALUE
        else if(choice == 4)
        {
            printf("Enter value to delete: ");
            scanf("%d", &value);

            if(head == NULL)
            {
                printf("List is empty!");
            }
            else
            {
                temp = head;
                while(temp != NULL && temp->data != value)
                {
                    temp = temp->next;
                }
                if(temp == NULL)
                {
                    printf("Element not found.");
                }
                else
                {
                    if(temp->prev != NULL)
                    {
                        temp->prev->next = temp->next;
                    }
                    else
                    {
                        head = temp->next;
                    }
                    if(temp->next != NULL)
                    {
                        temp->next->prev = temp->prev;
                    }
                    free(temp);
                }
            }
        }
        // DISPLAY
        else if(choice == 5)
        {
            temp = head;
            printf("\nLinked List: ");
            while(temp != NULL)
            {
                printf("%d <-> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
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