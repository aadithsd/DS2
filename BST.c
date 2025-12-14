#include<stdio.h>
#include<conio.h>


#define max 90
#define EMPTY -1

int bst[max];

void insert(int value)
{
    int i=0;
    while(i<max)
    {
        if(bst[i]==EMPTY)
        {
            bst[i]=value;
            return;
        }

        else if (value<bst[i])  //left child
            i=2*i+1;
        else if (value>bst[i])  //right child
            i=2*i+2;
        else
        {
            printf("duplicate value %d not inserted: ",value);
            return;
        }
    }
    printf("Tree overflow! Cannot insert %d. \n",value);
}

void display()
{
    int i;
    printf("Array representation of BST: \n");
    for(i=0;i<max;i++)
    {
        if(bst[i]!=EMPTY)
            printf("Index %d -> %d \n",i,bst[i]);
    }
}

void main()
{
    int i,n,val;
    //clrscr();
    for(i=0;i<max;i++)
    {
        bst[i]=EMPTY;
    }
    printf("Enter amount of elements to insert: ");
    scanf("%d",&n);
    printf("enter %d  values: \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        insert(val);
    }
    display();
    getch();
}