#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

struct node* Enternode(int data){
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode -> data = data;
    NewNode -> prev = NULL;
    NewNode -> next = NULL;
    return NewNode;    
}

struct node* takeInput(){
    int data = 0;
    scanf("%d",&data);
    struct node* head = NULL;
    struct node* tail = NULL;
    while(data != -1){
        struct node* newnode = Enternode(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode -> prev = tail;
            tail -> next = newnode;
            tail = tail -> next;
        }
        scanf("%d",&data);
    }
    return head;
}

struct node* insertHead(struct node* head, int data){
    struct node* newnode = Enternode(data);
    head -> prev = newnode;
    newnode -> next = head;
    head = newnode;
    return head;
}

void pushTail(struct node* head,int data){
    struct node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    struct node* newnode = Enternode(data);
    newnode -> prev = temp;
    temp -> next = newnode;
}

void insertNode(struct node* head, int data, int pos){
        
    struct node* temp = head;
    for(int i=0; i<pos-1 && temp != NULL; i++){
        temp = temp -> next;
    }

    struct node* newnode = Enternode(data);
    newnode -> next = temp -> next;
    temp -> next = newnode;
    newnode -> next -> prev = newnode;
    newnode -> prev = temp;
}

struct node* deleteHead(struct node* head){
    struct node* waste = head;
    head = head -> next;
    free(waste);
    return head;
}

void deleteNode(struct node* head, int pos){
    if(head == NULL){
        printf("\n!! ERROR: Linked List is Already Empty !!");
        return;
    }
    struct node* temp = head;
    for(int i=0; i<pos; i++){
        temp = temp -> next;
    }
    struct node* wasteNode = temp;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(wasteNode);
}

void printLL(struct node* head){
    printf("The Linked List is: ");
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void printLLReverse(struct node* head){
    if(head == NULL){
        printf("\n!! ERROR: LINKED LIST IS EMPTY !!\n");
        return;
    }
    printf("The Linked List in Reverse is: ");
    struct node* tail = head -> next;
    while(tail -> next != NULL){
        tail = tail -> next;
    }

    while(tail != head){
        printf("%d ", tail -> data);
        tail = tail -> prev;
    }
    printf("%d\n", tail -> data);
}

int main(){
    printf("\nEnter Elements of Doubly LinkedList: \n");
    struct node* head = takeInput();
    int ch;
    while(1){
        printf("\n1.Insert Element @ Head\n2.Insert Element @ Pos\n3.Insert Element @ Tail");
        printf("\n4.Delete Element @ Head\n5.Delete Element @ Pos");
        printf("\n6.Print Linked List\n7.Print Linked List in Reverse\n8.Exit");
        printf("\nEnter Choice(1/2/3/4/5/6): ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                head = insertHead(head,data);
                printf("INSERTION SUCCESSFULL !!\n");
                break;
                }
            case 2:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                printf("\nEnter Pos to enter at: ");
                int pos;
                scanf("%d",&pos);
                insertNode(head,data,pos);
                printf("INSERTION SUCCESSFULL !!\n");
                break;
            } 
            case 3:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                pushTail(head,data);
                printf("INSERTION SUCCESSFULL !!\n");
                break;
                }  
            case 4:{
                head = deleteHead(head);
                printf("DELETION SUCCESSFULL !!\n");
                break;
                }
            case 5:{
                printf("\nEnter Pos. of Data to delete: ");
                int pos;
                scanf("%d",&pos);
                deleteNode(head,pos);
                printf("DELETION SUCCESSFULL !!\n");
                break;
                }
            case 6:{
                printLL(head);
                break;
                }
            case 7:{
                printLLReverse(head);
                break;
            }
            case 8:{
                return 0;
                }
            default:
                printf("\n!! ERROR: INVALID OPTION, TRY AGAIN !!\n");
        }
    }
}