#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node* head)
{
    struct Node* ptr=head;
    do
    {
    printf("Element :%d\n",ptr->data);
    ptr= ptr->next;
    }while (ptr!=head);
    
}

struct Node* insertatfirst(struct Node *head,int data)
{
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node* p = head->next; 
    while (p->next!=head)
    {
        p=p->next;
    }
    // At this point p points to the last node of the circular linked list
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

void main ()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data= 7;
    head->next = second;
    
    // Linked second and third nodes
    second->data= 11;
    second->next = third;

    // Terminates the list at the third node
    third->data= 66;
    third->next = head;    
    printf("\nCircular Linked list before insertion:\n");
    linkedlistTraversal(head);
    printf("\nCircular Linked list after insertion:\n");
    head= insertatfirst(head,80);
    linkedlistTraversal(head);
}