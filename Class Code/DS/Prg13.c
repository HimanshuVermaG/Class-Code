// WAP to implement Queue using Array

#include<stdio.h>
#include<stdlib.h>
#define max 10

int queue [max],front=0,rear=0;
void insertion();
void deletion();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------\n");
        printf("\nOperation on Queue\n");
        printf("\n------------------------------\n");
        printf("\n1. Insert into Queue");
        printf("\n2. Delete from Queue");
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
    if(rear==max)
    {
        printf("Queue Overflow");
    }
    else
    {
        printf("Enter the Data = ");
        scanf("%d",&data);
        queue[rear]=data;
        rear=rear+1;

    }
}

void deletion()
{
    int data;
    if(front==rear)
    {
        printf("Queue Underflow");
    }
    else
    {
        data=queue[front];
        front=front+1;
    }
    
}
void display()
{
    int i;
    for (int i = 0; i <=rear; i++)
    {
        printf("\n%d",queue[i]);
    }
    
    
}
