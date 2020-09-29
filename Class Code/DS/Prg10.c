// WAP to implement polynomial using link list
// 3x^2 + 5x + 20
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int coff;
    int expo;
    struct node *next;
};
struct node *start=NULL;
void creatpolynomial();
void displaylist();

int main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------\n");
        printf("\nOperation on single link list\n");
        printf("\n------------------------------\n");
        printf("\n1. Creat plynomial");
        printf("\n2. Display the plynomial");
        printf("\n3. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n----Creat Link List----");
                creatpolynomial();
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

void creatpolynomial()
{
    struct node *ptr, *cpt;
    char ch1;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter info part of the node \n");
    scanf("%d",&ptr -> coff);
    scanf("%d",&ptr -> expo);
    start = ptr;
    ch1 =getchar();
    while (ch1=='Y'||ch1=='y')
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter info part of the node \n");
        scanf("%d",&cpt -> coff);
        scanf("%d",&cpt -> expo);
        ptr-> next= cpt;
        ptr = cpt;
        ch1 =getchar();
    }
    ptr->next=NULL;
}
void displaylist()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("Plynomial is Empty");
    }
    else
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("Data = %d %d \n",ptr->coff,ptr->expo);
            ptr=ptr->next;
        }
    }
}