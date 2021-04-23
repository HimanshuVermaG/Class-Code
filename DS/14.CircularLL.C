#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* EnterNode(int data){
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode -> data = data;
    NewNode -> next = NULL;
    return NewNode;
}

struct node* takeInput(){
    int data;
    scanf("%d",&data);
    struct node* head = NULL;
    struct node* tail = NULL;
    while(data != -1){
        struct node* newnode = EnterNode(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        scanf("%d",&data);
    }
    tail -> next = head;
    return head;
}

struct node* insertHead(struct node* head, int data){
    struct node* newnode = EnterNode(data);
    struct node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
    head = newnode;
    printf("!! Insertion Successfull !!\n");
    return head;
}

void pushTail(struct node* head, int data){
    struct node* newnode = EnterNode(data);
    struct node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
    printf("!! Insertion Successfull !!\n");
}

void insertNode(struct node* head, int data, int pos){
    struct node* newnode = EnterNode(data);
    struct node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp -> next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    printf("!! Insertion Successfull !!\n");
}

struct node* deleteHead(struct node* head){
    if(head == NULL){
        printf("\n!! ERROR: LINKED LIST IS AREADY EMPTY !!\n");
        return NULL;
    }
    if(head -> next == head){
        printf("\n!! WARNING: LINKED LIST IS NOW EMPTY !!\n");
        head = NULL;
        return head;
    }
    struct node* waste = head;
    struct node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = head -> next;
    head = head -> next;
    free(waste);
    printf("!! Deleteion Successfull !!\n");
    return head;
}

void deleteNode(struct node* head, int pos){
    struct node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp -> next;
    }
    struct node* waste = temp -> next;
    temp -> next = waste -> next;
    free(waste);
    printf("!! Deletion Successfull !!\n");
}

void printLL(struct node* head){
    if(head == NULL){
        printf("\n!! ERROR: LINKED LIST IS EMPTY !!\n");
        return;
    }
    printf("The Linked List is: ");
    struct node* temp = head -> next;
    printf("%d ",head -> data);
    while(temp != head){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    printf("\nEnter Elements of Circular LinkedList: \n");
    struct node* head = takeInput();
    int ch;
    while(1){
        printf("\n1.Insert Element @ Head\n2.Insert Element @ Pos\n3.Insert Element @ Tail");
        printf("\n4.Delete Element @ Head\n5.Delete Element @ Pos");
        printf("\n6.Print Linked List\n7.Exit");
        printf("\nEnter Choice(1/2/3/4/5/6): ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                head = insertHead(head,data);
                break;
                }
            case 2:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                printf("Enter Pos to enter at: ");
                int pos;
                scanf("%d",&pos);
                insertNode(head,data,pos);
                break;
            } 
            case 3:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                pushTail(head,data);
                break;
                }  
            case 4:{
                head = deleteHead(head);
                break;
                }
            case 5:{
                printf("\nEnter Pos. of Data to delete: ");
                int pos;
                scanf("%d",&pos);
                deleteNode(head,pos);
                break;
                }
            case 6:{
                printLL(head);
                break;
                }
            case 7:{
                return 0;
                }
            default:
                printf("\n!! ERROR: INVALID OPTION, TRY AGAIN !!\n");
        }
    }
}