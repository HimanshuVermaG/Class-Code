// WAP to implement Stack using Link list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *stack, *top;
void push();
void pop();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\n------------------------------\n");
        printf("\nOperation on Stack\n");
        printf("\n------------------------------\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n----Insert element into stack----\n");
                push();
                    break;
            case 2:
                printf("\n----Delete an element from stack----\n");
                pop();
                break;
            case 3:
                printf("\n----Display the element of stack----\n");
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
void push()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Info Part of Node\n");
    scanf("%d",&ptr->info);
    ptr->next=NULL;
    if(stack==NULL)
    {
        stack=ptr;
        top=ptr;
    }
    else
    {
        top->next=ptr;
        top=ptr;
    }
    
}
void pop()
{
    struct node *ptr,*cpt;
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        ptr=stack;
        while (ptr->next!=NULL)
        {
            cpt=ptr;
            ptr=ptr->next;
        }
        top=cpt;
        top->next=NULL;
        free(ptr);        
    }
    
}
void display()
{
    struct node *ptr;
    ptr=stack;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->info);
        ptr=ptr->next;
    }
    
}