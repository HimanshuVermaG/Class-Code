#include<stdio.h>
#include<stdlib.h>

#define size 3
int queue[3];
int front = -1, rear = -1;

int isFull(){
    if((front == rear + 1) || (front == 0 && rear == size-1)){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

void enqueue(int data){
    if(isFull()){
        printf("!! ERROR: THE QUEUE IS FULL !!\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % size;
    queue[rear] = data;
    printf("%d Enqueued SUCCESSFULLY\n",data);
}

void dequeue(){
    if(isEmpty()){
        printf("!! ERROR: THE QUEUE IS ALREADY EMPTY !!\n");
        return;
    }
    int data = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front + 1) % size;
    }
    printf("%d THE Dequeued SUCCESSFULLY !!\n",data);
}

void printQueue(){
    if(isEmpty()){
        printf("!! ERROR: THE QUEUE IS EMPTY !!\n");
        return;
    }
    
    printf("\nFront: %d",front); 
    printf("\nElements in Circular Queue are: "); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",queue[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", queue[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", queue[i]); 
    }
    printf("\nRear: %d",rear);
    printf("\n");
}

int main(){
    while(1){
        printf("\n1.Enqueue Data\n2.Dequeue Data\n3.Check if Full\n4.Check if Empty");
        printf("\n5.Print Queue\n6.Exit");
        int ch;
        printf("\nEnter Choice(1/2/3/4/5/6): ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter Data to Enqueue: ");
                int data;
                scanf("%d",&data);
                enqueue(data);
                break;
            }

            case 2:{
                dequeue();
                break;
            }

            case 3:{
                if(isFull()){
                    printf("\n!! THE QUEUE IS FULL !!\n");
                    break;
                }
                printf("\n!! THE QUEUE IS NOT FULL !!\n");
                break;
            }

            case 4:{
                if(isEmpty()){
                    printf("\n!! THE QUEUE IS EMPTY !!\n");
                    break;
                }
                printf("\n!! THE QUEUE IS NOT EMPTY !!\n");
                break;
            }

            case 5:{
                printQueue();
                break;
            }

            case 6:{
                return 0;
            }
        }
    }
}