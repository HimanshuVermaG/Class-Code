#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
 
void create_node(int coeff, int power, struct Node** head){
    struct Node *newnode, *temp;
    temp = *head;
    if (temp == NULL) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode -> coeff = coeff;
        newnode -> pow = power;
        *head = newnode;
        newnode -> next = (struct Node*)malloc(sizeof(struct Node));
        newnode = newnode -> next;
        newnode -> next = NULL;
    }
    else {
        newnode -> coeff = coeff;
        newnode -> pow = power;
        newnode -> next = (struct Node*)malloc(sizeof(struct Node));
        newnode = newnode -> next;
        newnode -> next = NULL;
    }
}
 
void polyadd(struct Node* poly1, struct Node* poly2, struct Node* ans){
    while (poly1 -> next && poly2 -> next) {

        if (poly1 -> pow > poly2 -> pow) {
            ans -> pow = poly1 -> pow;
            ans -> coeff = poly1 -> coeff;
            poly1 = poly1 -> next;
        }
 
        else if (poly1 -> pow < poly2 -> pow) {
            ans -> pow = poly2 -> pow;
            ans -> coeff = poly2 -> coeff;
            poly2 = poly2 -> next;
        }
 
        else {
            ans -> pow = poly1 -> pow;
            ans -> coeff = poly1 -> coeff + poly2 -> coeff;
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
 
        ans -> next = (struct Node*)malloc(sizeof(struct Node));
        ans = ans -> next;
        ans -> next = NULL;
    }
    while (poly1 -> next || poly2 -> next) {
        if (poly1 -> next) {
            ans -> pow = poly1 -> pow;
            ans -> coeff = poly1 -> coeff;
            poly1 = poly1 -> next;
        }
        if (poly2 -> next) {
            ans -> pow = poly2 -> pow;
            ans -> coeff = poly2 -> coeff;
            poly2 = poly2 -> next;
        }
        ans -> next = (struct Node*)malloc(sizeof(struct Node));
        ans = ans -> next;
        ans -> next = NULL;
    }
}
 
void  printPoly(struct Node* node){
    while (node -> next != NULL) {
        printf("%dx^%d", node -> coeff, node -> pow);
        node = node -> next;
        if (node -> coeff >= 0) {
            if (node -> next != NULL)
                printf(" + ");
        }
    }
}
 
int main(){
    struct Node *poly1 = NULL, *poly2 = NULL, *ans = NULL;
 
    // Create first list of 10x^2 - 3x^1 + 7x^0
     create_node(10, 2, &poly1);
     create_node(-3, 1, &poly1);
     create_node(7, 0, &poly1);
 
    // Create second list of -4x^1 - 4x^0
    create_node(-4, 1, &poly2);
    create_node(-4, 0, &poly2);

    printf("\n");
    printf("1st POLYNOMIAL: ");
     printPoly(poly1);
    
    printf("\n2nd POLYNOMIAL: ");
     printPoly(poly2);
 
    ans = (struct Node*)malloc(sizeof(struct Node));
 
    polyadd(poly1, poly2, ans);
 
    printf("\n");
    printf("\nADDED POLYNOMIAL: ");
     printPoly(ans);
 
}