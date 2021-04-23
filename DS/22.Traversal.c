#include<stdio.h>
#include<stdlib.h>

struct node {
    int item;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root) {
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d -> ", root->item);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL){
        return; 
    }
    printf("%d -> ", root->item);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->item);
}

struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertLeft(struct node* root,int value) {
    root->left = createNode(value);
    return root->left;
}

struct node* insertRight(struct node* root, int value) {
    root->right = createNode(value);
    return root->right;
}

int main(){
    int ch;
    struct node* root = createNode(1);
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root->left,4);
    insertRight(root->left,5);
    insertLeft(root->left->left,6);
    insertRight(root->right,7);
    while(1){
        printf("Traversal of Binary Tree");
        printf("\n1. Inorder Traversal");
        printf("\n2. Preorder Traversal");
        printf("\n3. Postorder Traversal");
        printf("\n4. Exit");
        printf("\n\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\n\n");
                break;
            case 2:
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\n\n");
                break;
            case 3:
                printf("\nPostorder traversal: ");
                postorder(root);
                printf("\n\n");
                break;
            case 4:
                return 1;
            default:
                printf("\nInvalid Choice!!\n\n");
                break;
            }
    }
}