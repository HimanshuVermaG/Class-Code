#include<stdio.h>
int A[100];
int sizeA = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void takeInput(){
    printf("Enter size: ");
    scanf("%d",&sizeA);
    printf("Enter data: ");
    for(int i=0; i<sizeA; i++){
        scanf("%d",&A[i]);
    }
}

void bubblesort(int ar[], int size){
    for(int i=0; i<size -1 ; i++){
        for(int j=0; j<size - i -1 ; j++){
            if(ar[j] > ar[j+1]){
                swap(&ar[j], &ar[j+1]);
            }
        }
    }
}

void printArr(int arr[], int size){
    printf("\nThe Array is: ");
    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    takeInput();
    printf("\nArray Before Sorting: ");
    printArr(A,sizeA);
    bubblesort(A,sizeA);
    printf("\nArray After Sorting: ");
    printArr(A,sizeA);
}