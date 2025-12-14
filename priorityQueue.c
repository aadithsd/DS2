//priority queue
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{
    int data;
    struct Node *next;
    int priority;
};
struct Node *front = NULL;

void insert()
{
    int pr,item;
    struct Node *temp;
    struct Node *nextNode;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("\n overflow.");
        return;
    }
    printf("\nEnter Value: ");
    scanf("%d",&item);
    printf("enter priority: (lower number=higher priority): ");
    scanf("%d",&pr);

    newNode->data=item;
    newNode->priority=pr;
    newNode->next=NULL;

    if(front==NULL || pr<front ->priority){
        newNode->next=front;
        front=newNode;
        return;
    }
    temp=front;
    while(temp->next != NULL){
        nextNode=temp->next;
        if(newNode->priority>pr)
            break;
        temp=temp->next;

    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteAtBeginning() {
    if (front == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("\nDeleted:%d, priority:%d\n",temp->data,temp->priority);
    front = front->next;
    free(temp);
}

void display()
{
    struct Node *temp = front;
    if(temp==NULL)
    {
        printf("\n Queue is empty.");
        return;
    }
    printf("\n priority queue: \n");
    while(temp!=NULL){
        printf("value:%d[P:%d]->",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("NULL\n");
}


int main()
{
    while(1){
    int ch;
    printf("---PRIORITY QUEUE---");
    printf("\n1.insert \n2.delete \n3.display \n4.exit \n");
    printf("\nenter operation: ");
    scanf("%d",&ch);
    switch(ch){
        case 1: insert();
                break;
        case 2: deleteAtBeginning();
                break;
        case 3: display();
                break;
        case 4: exit(0);
        default: printf("enter valid operation. ");
    }
    }
}
