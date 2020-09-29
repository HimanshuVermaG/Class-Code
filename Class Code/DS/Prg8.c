// Creating Single Link List
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
void creatlist();
void displaylist();

int main()
{
    int ch;
    while(1)
    {
        printf("\n------------------------------\n");
        printf("\nOperation on single link list\n");
        printf("\n------------------------------\n");
        printf("\n1. Creat single link list");
        printf("\n2. Display the list");
        printf("\n3. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\n----Creat Link List----");
            creatlist();
            break;
        case 2:
            printf("\n----Display the List----");
            displaylist();
            break;
        case 3:
            printf("\n----Exiting----");
            return 0;
            break;
        
        default:
            printf("\nInvalid Input\n");
            break;
        }
    }
    return 0;
}
void creatlist()
{
    struct node *ptr,*cpt;
    char ch1;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Info Part of the Node\n");
    scanf("%d",&ptr->info);
    start=ptr;
    ch1=getchar();
    while(ch1=='Y'||ch1=='y')
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Info part of the Node\n");
        scanf("%d",&cpt->info);
        ptr->next=cpt;
        ptr=cpt;
        ch1=getchar();
    }
    ptr->next=NULL;
}
void displaylist()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is Empty");
    }
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("Data = %d\n",ptr->info);
            ptr=ptr->next;
        }
    }
}
