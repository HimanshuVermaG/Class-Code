#include<stdio.h>
#include<stdlib.h>

struct Qnode{
    int data;
    struct Qnode* next;
};

struct Queue{
    struct Qnode* front;
    struct Qnode* rear;
};

struct Qnode* EnterNode(int data){
    struct Qnode* newnode = (struct Qnode*)malloc(sizeof(struct Qnode));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q -> front = NULL;
    q -> rear = NULL;
    return q;
}

int isEmpty(struct Queue* queue){
    return (queue -> front == NULL);
}

void enqueue(struct Queue* queue, int data){
    struct Qnode* newnode = EnterNode(data);
    if(queue -> rear == NULL){
        queue -> front = newnode;
        queue -> rear = newnode;
        printf("\n%d SUCCESSFULLY ENQUEUED !!\n", data);
        return;
    }
    queue -> rear -> next = newnode;
    queue -> rear = newnode;
    queue -> rear -> next = NULL;
    printf("\n%d SUCCESSFULLY ENQUEUED !!\n", data);
}

void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("\n!! ERROR: THE QUEUE IS ALREADY EMPTY!!\n");
        return;
    }
    struct Qnode* waste = queue -> front;
    queue -> front = queue -> front -> next;
    if(queue -> front == NULL){
        queue -> rear = NULL;
    }
    printf("\n%d SUCCESSFULLY DEQUEUED !!\n",waste -> data);
    free(waste);
}

void printQueue(struct Queue* queue){
    if(queue == NULL){
        printf("\n!! ERROR: THE QUEUE IS EMPTY !!");
        return;
    }
    struct Qnode* temp = queue -> front;
    printf("\nTHE QUEUE IS: ");
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    struct Queue* mainQueue = NULL;

    while(1){
        printf("\n~~~~~~~~~~~~~~~~\n1.Create Queue\n2.Push\n3.Pop\n4.Check for Queue Empty");
        printf("\n5.Print Queue\n6.Exit\n~~~~~~~~~~~~~~~~\n");
        printf("\nEnter Choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){

            case 1:{
                mainQueue = createQueue();
                printf("\nQUEUE SUCCESSFULLY CREATED");
                break;
            }

            case 2:{
                printf("\nEnter Element to Enter: ");
                int data;
                scanf("%d",&data);
                enqueue(mainQueue,data);
                break;
            }

            case 3:{
                dequeue(mainQueue);
                break;
            }

            case 4:{
                if(isEmpty(mainQueue)){
                    printf("\n!! THE Queue IS EMPTY !!\n");
                }
                else{
                    printf("\n!! THE Queue IS NON EMPTY !!\n");
                }
                break;
            }

            case 5:{
                printQueue(mainQueue);
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

