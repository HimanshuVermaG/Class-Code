// Push,Pop,and Peek Operation in stack.
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Element %d pushed successfully in Stack\n", val);
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Element %d poped successfully from Stack\n", val);
    }
}
int peek(struct stack *sp, int i)
{
    int arrInd = sp->top - i + 1;
    if (arrInd < 0)
    {
        printf("Not a valid Position\n");
    }
    else
    {
        return sp->arr[arrInd];
    }
}
int stackTop(struct stack *sp)
{
    int val = sp->arr[sp->top];
    printf("Stack Top value is : %d\n", val);
}
int stackBottom(struct stack *sp)
{
    int val = sp->arr[0];
    printf("Stack Bottom value is : %d\n", val);
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("# Stack has been created successfully!!\n");

    push(sp, 40);
    push(sp, 45);
    push(sp, 46);
    push(sp, 47);
    push(sp, 48);
    push(sp, 48);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    stackTop(sp);
    stackBottom(sp);
    return 0;
}