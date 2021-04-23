#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct StackUsingLL{
    int data;
    struct StackUsingLL* next;
};

struct StackUsingLL* EnterData(int data){
    struct StackUsingLL* stackNode = (struct StackUsingLL*)malloc(sizeof(struct StackUsingLL));
    stackNode -> data = data;
    stackNode -> next = NULL;
    return stackNode;
}

bool isEmpty(struct StackUsingLL* stackHead){
    return !stackHead;
}

void push(struct StackUsingLL** stackHead, int data){
    struct StackUsingLL* newnode = EnterData(data);
    newnode -> next = *stackHead;
    *stackHead = newnode;
    printf("\n%d IS SUCCESSFULLY PUSHED\n",data);
}

void pop(struct StackUsingLL** stackHead){
    if(isEmpty(*stackHead)){
        printf("\n!! ERROR: STACK IS ALREADY EMPTY !!\n");
        return;
    }
    struct StackUsingLL* temp = *stackHead;
    *stackHead = (*stackHead) -> next;
    printf("\n%d IS SUCCESSFULLY POPPED\n",temp -> data);
    free(temp);
}

struct StackUsingLL* createStack(){
    printf("\nEnter Data: ");
    int data;
    scanf("%d",&data);
    struct StackUsingLL* stackHead = NULL;
    while(data != -1){
        push(&stackHead,data);
        scanf("%d",&data);
    }
    return stackHead;
}

void printStack(struct StackUsingLL* stackHead){
    printf("\nThe Stack is: ");
    struct StackUsingLL* temp = stackHead;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    struct StackUsingLL* mainStack = NULL;
    while(1){
        printf("\n1.Create Stack\n2.Push\n3.Pop\n4.Check If Stack Is Empty");
        printf("\n5.Print Stack\n6.Exit");
        printf("\nEnter Choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                mainStack = createStack();
                printf("\nSTACK SUCCESSFULLY CREATED");
                break;
            }
            case 2:{
                printf("\nEnter Element to Enter: ");
                int data;
                scanf("%d",&data);
                push(&mainStack,data);
                break;
            }
            case 3:{
                pop(&mainStack);
                break;
            }
            case 4:{
                if(isEmpty(mainStack)){ 
                    printf("\n!! THE STACK IS EMPTY !!\n");
                }
                else{
                    printf("\n!! THE STACK IS NON EMPTY !!\n");
                }
                break;
            }
            case 5:{
                printStack(mainStack);
                break;
            }
            case 6:{
                return 0;
            }
            default:{
                printf("\n!! ERROR: INVALID OPTION, TRY AGAIN !!");
            }
        }
    }
}

