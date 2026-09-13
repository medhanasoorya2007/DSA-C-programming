#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

int main()
{
    int n,value;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    struct node *head=NULL, *temp=NULL, *newNode=NULL;
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
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}