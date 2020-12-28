#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Pushed Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        printf("Poped Element : %d", x);
    }
}
struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("Value at Position %d is : %d\n", pos, ptr->data);
    }
    else
    {
        printf("Wrong Input!!\n");
    }
}
int main()
{

    top = push(top, 48);
    top = push(top, 48);
    top = push(top, 47);
    linkedlistTraversal(top);
    peek(2);
    top = pop(top);
    return 0;
}