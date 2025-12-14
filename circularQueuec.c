#include<stdio.h>
#include<conio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int item;
    if((rear+1)%MAX==front){
        printf("\nQueue overflow!cannot insert");
        return;
    }
    printf("\nEnter element to insert: ");
    scanf("%d",&item);

    if(front==-1 && rear==-1)
        rear=front=0;
    else
        rear = (rear+1)%MAX;
    queue[++rear]=item;
    printf("\n%d inserted into the queue.\n",item);

}
void delete()
{
    if(front==-1){
        printf("underflow, queue is empty.");
        return;
    }
    printf("\n %d deleted \n",queue[front]);
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
}

void display()
{
    int i;
    i=front;
    if(front==-1){
        printf("underflow, queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");

    for(i=front;i!=rear;i=(i+1)%MAX)
    {
        printf("%d , ",queue[i]);
    }
    //printf("%d , ",queue[i]);
    printf("\n");
}
int main()
{
    while(1)
    {
    int ch;
    printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
    printf("\nEnter choice: ");
    scanf("%d",&ch);

    switch(ch)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            defualt: printf("\n enter valid option");
        }
    }
}
