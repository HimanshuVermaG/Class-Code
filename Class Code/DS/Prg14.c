// WAP to implement Circular Queue using Array

#include<stdio.h>
#include<stdlib.h>
#define max 10

int cqueue [max],front=0,rear=0;
void insertion();
void deletion();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------\n");
        printf("\nOperation on Cqueue\n");
        printf("\n------------------------------\n");
        printf("\n1. Insert into Cqueue");
        printf("\n2. Delete from Cqueue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n----Insert element into Queue----\n");
                insertion();
                    break;
            case 2:
                printf("\n----Delete an element from Queue----");
                deletion();
                break;
            case 3:
                printf("\n----Display the element of Queue----");
                display();
                break;
            case 4:
                printf("\n----Exiting----");
                exit(4);
                break;
            
            default:
                printf("\nInvalid Input\n");
                break;
        }
    }
}
void insertion()
{
    int data;
    if((rear+1)%max==front)
    {
        printf("Cqueue Overflow");
    }
    else
    {
        printf("Enter the Data = ");
        scanf("%d",&data);
        cqueue[rear]=data;
        rear=(rear+1)%max;

    }
}

void deletion()
{
    int data;
    if(front==rear)
    {
        printf("Cqueue Underflow");
    }
    else
    {
        data=cqueue[front];
        front=(front+1)%max;
    }
    
}
void display()
{
    int i=front;
    while (i!=rear-1)
    {
        printf("\n%d",cqueue[i]);
        i=(i+1)%max;
    }
    
}
