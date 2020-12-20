#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * insertatFirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data = data;
    return ptr;
}

struct Node * insertatEnd(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next!=NULL)
    {
        p=p->next;
    }
    
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node * insertAfterNode(struct Node *head,struct Node *prevNode,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next= ptr;
    return head;
}

struct Node * insertatIndex(struct Node *head,int data,int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
}

void linkedlistTraversal(struct Node* ptr)
{
    while (ptr!=NULL)
    {
    printf("Element :%d\n",ptr->data);
    ptr= ptr->next;
    }
    
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
    third->next = NULL;    
    printf("Linked list before insertion:-\n");
    linkedlistTraversal(head);
    // head= insertatFirst(head,56);
    // head= insertatIndex(head,156,1);
    // head = insertatEnd(head,156);
    head = insertAfterNode(head,third,156);
    printf("Linked list after insertion:-\n");
    linkedlistTraversal(head);
}