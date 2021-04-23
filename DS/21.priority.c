#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node* next;
};

struct node* EnterNode(int data,int priority){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> priority = priority;
    newnode -> next = NULL;
    return newnode;
}

void push(struct node** head, int data, int pr){
    struct node* temp = (*head);
    struct node* newEntry = EnterNode(data,pr);
    if((*head) == NULL){
        (*head) = newEntry;
        printf("%d PUSHED SUCCESSFULLY\n",data);
        return;
    }
    if((*head) -> priority > pr){
        newEntry -> next = *head;
        (*head) = newEntry;
    }
    else{
        while(temp -> next != NULL && temp -> next -> priority < pr){
            temp = temp -> next;
        }
        newEntry -> next = temp -> next;
        temp -> next = newEntry;
    }
    printf("%d PUSHED SUCCESSFULLY\n",data);
}

void pop(struct node** head){
    struct node* temp = (*head);
    (*head) = (*head) -> next;
    printf("\n%d IS POPPED SUCCESSFULLY\n",temp -> data);
    free(temp);
}

int isEmpty(struct node** head){
    return (*head) == NULL;
}

void printPQueue(struct node** head){
    if(isEmpty(head)){
        printf("\n!! ERROR: THE QUEUE IS EMPTY!!");
        return;
    }
    printf("\nThe Priority Queue is: ");
    struct node* temp = (*head);
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

struct node* takeInput(){
    int data, priority;
    printf("\nEnter Data: ");
    scanf("%d",&data);
    struct node* queueHead = NULL;
    while(data != -1){
        printf("Enter Priority of %d: ",data);
        scanf("%d",&priority);
        push(&queueHead,data,priority);
        printf("\nEnter Data: ");
        scanf("%d",&data);
    }
    printf("\nPRIORITY QUEUE CREATED SUCCESSFULLY\n");
    return queueHead;
}

int main(){
    struct node* PQueue = NULL;
    while(1){
        printf("\n1.Create Priority Queue\n2.Push Data\n3.Pop Data");
        printf("\n4.Check if Empty\n5.Print Queue\n6.Exit");
        int ch;
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                PQueue = takeInput();
                break;
            }
            case 2:{
                printf("\nEnter Data: ");
                int data;
                scanf("%d",&data);
                printf("Enter Priority: ");
                int pr;
                scanf("%d",&pr);
                push(&PQueue,data,pr);
                break;
            }
            case 3:{
                pop(&PQueue);
                break;
            }
            case 4:{
                if(isEmpty(&PQueue)){
                    printf("\n!! THE QUEUE IS EMPTY !!\n");
                    break;
                }
                printf("\n!! THE QUEUE IS NOT EMPTY !!\n");
                break;
            }
            case 5:{
                printPQueue(&PQueue);
                break;
            }
            case 6:{
                return 0;
            }
        }
    }
}
