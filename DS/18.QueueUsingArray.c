#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;
};

struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue -> capacity = capacity;
    queue -> front = 0;
    queue -> size = 0;
    queue -> rear = 0;
    queue -> arr = (int*)malloc(queue -> capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue){
    return (queue -> size == queue -> capacity);
}

int isEmpty(struct Queue* queue){
    return (queue -> size == 0);
}

void enqueue(struct Queue* queue, int data){
    if(isFull(queue)){
        printf("\n!! ERROR: THE QUEUE IS ALREADY FULL !!");
        return;
    }
    queue -> rear = (queue -> rear + 1) % (queue -> capacity);
    queue -> arr[queue -> rear] = data;
    (queue -> size)++;
    printf("%d SUCCESSFULLY ENQUEUED !!\n",data);
}

void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("\n!! ERROR: THE QUEUE IS ALREADY EMPTY !!");
        return;
    }
    int data = queue -> arr[queue -> front];
    queue -> front = (queue -> front + 1) % (queue -> capacity);
    (queue -> size)--;
    printf("%d SUCCESSFULLY DEQUEUED !!\n",data);
}

int front(struct Queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue -> arr[queue -> front];
}

int rear(struct Queue* queue){
    if(isFull(queue)){
        return INT_MIN;
    }
    return queue -> arr[queue -> rear];
}

int getSize(struct Queue* queue){
    return (queue -> size);
}

void printQueue(struct Queue* queue){
    int i = queue -> front;
    while(front != rear){
        printf("%d ",queue -> arr[i]);
        //i = (i+1) % (queue -> capacity);
        i++;
    }
    //printf("%d",queue -> arr[i]);
}

int main(){
    struct Queue* mainQueue = createQueue(10);
    
    while(1){
        printf("\n1.Create Queue\n2.Push\n3.Pop\n4.Size of Queue\n5.Check If Queue Is Empty");
        printf("\n6.Check If Queue Is Full\n7.Print Queue\n8.Exit");
        printf("\nEnter Choice: ");
        int ch;
        scanf("%d",&ch);
        switch(ch){

            case 1:{
                printf("\nEnter Capacity of Queue: ");
                int capacity;
                scanf("%d",&capacity);
                mainQueue = createQueue(capacity);
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
                printf("\nThe Size of Queue is: %d\n",getSize(mainQueue));
                break;
            }

            case 5:{
                if(isEmpty(mainQueue)){
                    printf("\n!! THE Queue IS EMPTY !!\n");
                }
                else{
                    printf("\n!! THE Queue IS NON EMPTY !!\n");
                }
                break;
            }

            case 6:{
                if(isFull(mainQueue)){
                    printf("\n!! THE Queue IS FULL !!\n");
                }
                else{
                    printf("\n!! THE Queue IS NOT FULL !!\n");
                }
                break;
            }

            case 7:{
                printQueue(mainQueue);
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
