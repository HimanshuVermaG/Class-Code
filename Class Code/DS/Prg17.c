#include<stdio.h>
#include<stdlib.h>

struct node
{
    int pri;
    int info;
    struct node *next;
};
struct node *queue; 
void insertion();
void deletion();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------\n");
        printf("\nOperation on Priority Queue\n");
        printf("\n------------------------------\n");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n~~~~~~~~~~~~\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n----Insert element into Priority Queue----\n");
                insertion();
                    break;
            case 2:
                printf("\n----Delete an element from Priority Queue----\n");
                deletion();
                break;
            case 3:
                printf("\n----Display the element of Priority Queue----\n");
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
    struct node *ptr,*cpt,*cpt1;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the info part and priority value of the node\n");
    scanf("%d %d",&ptr->info,&ptr->pri);
    cpt = queue;
    if(queue==NULL||ptr->pri< queue->pri)
    {
        ptr->next= queue;
        queue=ptr;
    }
    else
    {
        cpt=queue;
        while(cpt->pri<=ptr->pri&&cpt!=NULL)
        {
            cpt=cpt->next;
        }
        ptr->next=cpt->next;
        cpt1->next=ptr;
    }
}

void deletion()
{
    struct node *ptr;
    if(queue==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        ptr=queue;
        queue->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr=queue;
    while(ptr!=NULL)
    {
        printf("%d %d",ptr->info,ptr->pri);
        ptr=ptr->next;
    }
}