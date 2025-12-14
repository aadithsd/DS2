#include<stdio.h>
#include<conio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int item;
    if(rear==MAX-1){
        printf("\nQueue overflow!cannot insert");
        return;
    }
    printf("\nenter element to insert: ");
    scanf("%d",&item);

    if(front==-1)
        front=0;
    queue[++rear]=item;
    printf("\n%d inserted into the queue.\n",item);

}
void delete()
{
    if(front==-1 || front>rear){
        printf("underflow, queue is empty.");
        return;
    }
    printf("\n %d deleted \n",queue[front]);
    front++;
}

void display()
{
    int i;
    if(front==-1 || front>rear){
        printf("underflow, queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");

    for(i=front;i<=rear;i++){
        printf("%d , ",queue[i]);
    }
    printf("\n");
}
int main()
{
    while(1)
    {
    int ch;
    printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
    printf("\nenter choice: ");
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
