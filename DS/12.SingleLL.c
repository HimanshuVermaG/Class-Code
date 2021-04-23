#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* Enternode(int data){
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode -> data = data;
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
            tail -> next = newnode;
            tail = tail -> next;
        }
        scanf("%d",&data);
    }
    return head;
}

struct node* insertHead(struct node* head, int data){
    struct node* newnode = Enternode(data);
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

}

struct node* deleteHead(struct node* head){
    head = head -> next;
    return head;
}

void deleteNode(struct node* head, int pos){
    if(head == NULL){
        printf("\n!! ERROR: Linked List is Already Empty !!");
        return;
    }
    struct node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp -> next;
    }
    struct node* wasteNode = temp -> next;
    temp -> next = wasteNode -> next;
    free(wasteNode);
}

void printLL(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    printf("\nEnter Elements of LinkedList: \n");
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
                printf("\nINSERTION SUCCESSFULL !!");
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
                printf("\nINSERTION SUCCESSFULL !!");
                break;
            } 
            case 3:{
                printf("\nEnter Data to Enter: ");
                int data;
                scanf("%d",&data);
                pushTail(head,data);
                printf("\nINSERTION SUCCESSFULL !!");
                break;
                }  
            case 4:{
                head = deleteHead(head);
                printf("\nDELETION SUCCESSFULL !!");
                break;
                }
            case 5:{
                printf("\nEnter Pos. of Data to delete: ");
                int pos;
                scanf("%d",&pos);
                deleteNode(head,pos);
                printf("\nDELETION SUCCESSFULL !!");
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
                printf("!! ERROR: INVALID OPTION, TRY AGAIN!!");
        }
    }
}
