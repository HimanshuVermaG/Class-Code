#include<stdio.h>
#include<stdlib.h>
void inorder();
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node* root = NULL;
struct node*new_node(char data)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=data;
    return (p);
}
struct node* insertRight(struct node* root, int value)

{
    root->right = new_node(value);
    return root->right;
};
struct node* insertLeft(struct node* root, int value)

{
    root->left = new_node(value);
    return root->left;
};
int main()
{
    struct node* root = new_node('A');
    root=new_node('A');
    root->left=new_node('B');
    root->right=new_node('C');
    root->left->left=new_node('D');
    root->left->right=new_node('E');

    inorder(root);
}
void inorder(struct node *root){
    if(root==NULL){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}