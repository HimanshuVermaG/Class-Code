#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr, struct Node *p)
{
    printf("\nLinked list traversal from start to end:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\nLinked list traversal from end to start:\n");
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->prev;
    }
}

void main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = fourth;

    fourth->prev = third;
    ;
    fourth->data = 4;
    fourth->next = NULL;

    linkedlisttraversal(head, fourth);
}