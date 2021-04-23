#include<stdio.h>
#include<stdlib.h>

struct BSTnode{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};

struct BSTnode* Enternode(int data){
    struct BSTnode* newnode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

//Print BST
void printTree(struct BSTnode* root){
    if(root == NULL){
        return;
    }
    printf("\n%d: ",root -> data);
    if(root -> left != NULL){
        printf("L:%d",root -> left -> data);
    }
    else{
        printf("L:-1");
    }
    if(root->right != NULL){
        printf(" R:%d",root -> right -> data);
    }
    else{
        printf("R:-1");
    }
    printTree(root -> left);
    printTree(root -> right);
}

//Insert A Node in BST
struct BSTnode* insertNode(struct BSTnode* root,int data){
    if(root == NULL){
        return Enternode(data);
    }
    if(root -> data > data){
        root -> left = insertNode(root -> left,data);
    }
    else{
        root -> right = insertNode(root -> right, data);
    }
    return root;  
}

//Search A Node in BST
struct BSTnode* searchNode(struct BSTnode* root,int data){
    if(root == NULL || root -> data == data){
        return root;
    }
    if(root -> data > data){
        return searchNode(root -> left,data);
    }
    else if(root -> data < data){
        return searchNode(root -> right, data);
    }
    else{
        return NULL;
    }
}

//The largest value element on left of node will be Inorder Predecessor
struct BSTnode* MaxValueNode(struct BSTnode* root){
    struct BSTnode* current = root;
    while(current != NULL && current -> right != NULL){
        current = current -> right;
    }
    return current;
}

//The minimum value element on right of the node will be Inorder Successor
struct BSTnode* MinValueNode(struct BSTnode* root){
    struct BSTnode* current = root;
    while(current != NULL && current -> left != NULL){
        current = current -> left;
    }
    return current;
}

struct BSTnode* deleteNode(struct BSTnode* root, int data){
    if(root == NULL){
        return root;
    }
    /*  IF THE DATA TO DELETE IS LESS THAN NODE'S DATA,
        IT MUST LIE IN LEFT SUBTREE
    */
    if(data < root -> data){
        root -> left = deleteNode(root -> left, data);
    }
    /*  IF THE DATA TO DELETE IS GREATER THAN NODE'S DATA,
        IT MUST LIE IN RIGHT SUBTREE
    */
    else if(data > root -> data){
        root -> right = deleteNode(root -> right, data);
    }
    /*  IF THE DATA TO DELETE IS EQUAL TO NODE'S DATA,
    */
    else if(data == root -> data){
        //NODE HAS ZERO OR ONE CHILD
        if(root -> left == NULL){
            struct BSTnode* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            struct BSTnode* temp = root -> left;
            free(root);
            return temp;
        }
        //NODE HAS TWO CHILD
        else{
            printf("Which Node Do You Want Instead of %d",data);
            printf("\n1.INORDER PREDECESSOR\n2.INORDER SUCCESSOR");
            printf("\nEnter Choice (1/2): ");
            int ch;
            scanf("%d",&ch);
            switch (ch){
                case 1:{
                    struct BSTnode* temp = MaxValueNode(root -> left);
                    root -> data = temp -> data;
                    root -> left = deleteNode(root -> left,temp -> data);
                    break;
                }

                case 2:{
                    struct BSTnode* temp = MinValueNode(root -> right);
                    root -> data = temp -> data;
                    root -> right = deleteNode(root -> right,temp -> data);
                    break;
                }

                default:{
                    printf("\n!! ERROR: INVALID OPTION, TRY AGAIN !!");
                }
            }
        }
    }
    /* IF THE NODE IS NOT FOUND IN THE TREE
    */
    else{
        return NULL;
    }
    return root;
}

int main(){
    struct BSTnode* root = NULL;
    
    while(1){
        printf("\n1.CREATE TREE\n2.INSERT DATA\n3.DELETE DATA\n4.SEARCH DATA\n5.MIN VALUE NODE\n6.MAX VALUE NODE\n7.PRINT TREE\n8.EXIT");
        printf("\nEnter Choice (1/2/3/4/5/6): ");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter Root Data: ");
                int rootData;
                scanf("%d",&rootData);
                root = insertNode(root, rootData);
                printf("TREE SUCCESSFULL CREATED WITH ROOT = %d !!\n",rootData);
                break;
            }

            case 2:{    
                printf("Enter Data To Insert: ");
                int data;
                scanf("%d",&data);
                root = insertNode(root,data);
                printf("%d SUCCESSFULLY INSERTED !!\n",data);
                break;
            }

            case 3:{
                printf("Enter Data To Delete: ");
                int data;
                scanf("%d",&data);
                struct BSTnode* temp = deleteNode(root,data);
                if(root != NULL){
                    root = temp;
                    printf("%d SUCCESSFULLY DELETED !!\n",data);
                    break;
                }
                else{
                    printf("!! ERROR: %d NOT FOUND IN BST !!\n",data);
                    break;
                }
            }
            
            case 4:{
                printf("Enter Data to Search: ");
                int data;
                scanf("%d",&data);
                struct BSTnode* temp = searchNode(root,data);
                if(temp){
                    printf("%d FOUND IN THE TREE !!\n",temp -> data);
                }
                else{
                    printf("%d NOT FOUND IN THE TREE !!\n",data);
                }
                break;
            }

            case 5:{
                printf("The MIN VALUE NODE IS: %d\n",MinValueNode(root)->data);
                break;
            }

            case 6:{
                printf("The MAX VALUE NODE IS: %d\n",MaxValueNode(root)->data);
                break;
            }

            case 7:{
                printf("THE TREE IS: \n");
                printTree(root);
                printf("\n");
                break;
            }

            case 8:{
                return 0;
            }
        }
    }
}

