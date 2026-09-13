#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

int main()
{
    int n,value;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    struct node *head=NULL, *temp=NULL, *newNode=NULL;

    for(int i=0;i<n;i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d",&value);

        newNode->data=value;
        newNode->prev=NULL;
        newNode->next=head;

        if(head!=NULL)
        {
            head->prev=newNode;
        }

        head=newNode;
    }

    temp=head;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}