#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *temp= NULL, *newNode= NULL;

    int n, value, choice, pos;

    // Create initial linked list
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&value);
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL){
            head=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
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
            newNode->next = head;
            head = newNode;
        }

        // INSERT AT END
        else if(choice == 2)
        {
            printf("Enter element: ");
            scanf("%d", &value);

            newNode = malloc(sizeof(struct node));
            newNode->data = value;
            newNode->next = NULL;

            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                temp = head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
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
                newNode->next = head;
                head = newNode;
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
            temp = head;
            printf("\nLinked List: ");
            while(temp != NULL)
            {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
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
