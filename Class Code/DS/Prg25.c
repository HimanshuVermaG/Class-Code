// Q WAP to implement Binary Tree
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int item;
    struct node* left;
    struct node* right;
};

// Inorder Traversal
void inorderTravesal(struct node*root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTravesal(root->left);
    printf("%d ->",root->item);
    inorderTravesal(root->right);
}

// Preorder Traversal
void preorderTravesal(struct node*root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ->",root->item);
    inorderTravesal(root->left);
    inorderTravesal(root->right);
}

// Postorder Traversal
void postorderTravesal(struct node*root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTravesal(root->left);
    inorderTravesal(root->right);
    printf("%d ->",root->item);
}


// Creat a new node
struct node* createNode(int value)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode ->item = value;
    newNode ->left = NULL;
    newNode ->right = NULL;

    return newNode; 
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value)

{
    root->left = createNode(value);
    return root->left;
};

// Insert on the left of the node
struct node* insertRight(struct node* root, int value)

{
    root->right = createNode(value);
    return root->right;
};

int main ()
{
    struct node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root,3);
    insertLeft(root->left,4);
    insertLeft(root->right,9);
    insertRight(root->left,11);
    insertRight(root->right,10);

    printf("Inoder traversal\n");
    inorderTravesal(root);
    printf("\nPreoreder traversal\n");
    preorderTravesal(root);
    printf("\nPostoreder traversal\n");
    postorderTravesal(root);
}