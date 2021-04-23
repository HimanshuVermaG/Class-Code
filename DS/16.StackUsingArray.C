#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct StackUsingArray {
    int *data;
    int capacity;
    int nextIndex;
};

struct StackUsingArray* createStack(int capacity){
    struct StackUsingArray* stack = (struct StackUsingArray*)malloc(sizeof(struct StackUsingArray));
    stack -> capacity = capacity;
    stack -> data = (int*)malloc(stack -> capacity * sizeof(int));
    stack -> nextIndex = 0;
    return stack;
}

int getSize(struct StackUsingArray* stack){
    return stack -> nextIndex;
}

bool isEmpty(struct StackUsingArray* stack){
    return stack->nextIndex == 0;
}

bool isFull(struct StackUsingArray* stack){
    return stack -> nextIndex == stack -> capacity;
}

void push(struct StackUsingArray* stack,int data){
    if(isFull(stack)){
        printf("!! ERROR: STACK IS FULL !!\n");
        return;
    }
    stack -> data[stack->nextIndex] = data;
    stack -> nextIndex++;
    printf("%d IS SUCCESSFULLY PUSHED\n",data);
}

void pop(struct StackUsingArray* stack){
    if(isEmpty(stack)){
        printf("\n!! ERROR: STACK IS ALREADY EMPTY !!\n");
        return;
    }
    printf("\n%d IS SUCCESSFULLY POPPED\n",stack -> data[stack -> nextIndex-1]);
    stack -> nextIndex--;
}

void printStack(struct StackUsingArray* stack){
    printf("\nThe Stack is: ");
    for(int i= stack -> nextIndex - 1; i>=0; i--){
        printf("%d ",stack->data[i]);
    }
    printf("\n");
}

int main(){
    struct StackUsingArray* mainStack;
    while(1){
        printf("\n1.Create Stack\n2.Push\n3.Pop\n4.Size of Stack\n5.Check If Stack Is Empty");
        printf("\n6.Check If Stack Is Full\n7.Print Stack\n8.Exit");
        printf("\nEnter Choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter Capacity of Stack: ");
                int capacity;
                scanf("%d",&capacity);
                mainStack = createStack(capacity);
                printf("STACK SUCCESSFULLY CREATED\n");
                break;
            }
            case 2:{
                printf("\nEnter Element to Enter: ");
                int data;
                scanf("%d",&data);
                push(mainStack,data);
                break;
            }
            case 3:{
                pop(mainStack);
                break;
            }
            case 4:{
                printf("\nThe Size of Stack is: %d\n",getSize(mainStack));
                break;
            }
            case 5:{
                if(isEmpty(mainStack)){
                    printf("\n!! THE STACK IS EMPTY !!\n");
                }
                else{
                    printf("\n!! THE STACK IS NON EMPTY !!\n");
                }
                break;
            }
            case 6:{
                if(isFull(mainStack)){
                    printf("\n!! THE STACK IS FULL !!\n");
                }
                else{
                    printf("\n!! THE STACK IS NOT FULL !!\n");
                }
                break;
            }
            case 7:{
                printStack(mainStack);
                break;
            }
            case 8:{
                return 0;
            }
            default:{
                printf("\n!! ERROR: INVALID OPTION, TRY AGAIN !!");
            }
        }
    }
}