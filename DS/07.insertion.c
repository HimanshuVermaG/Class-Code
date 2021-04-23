#include<stdio.h>
int A[100];
int sizeA = 0;

void takeInput(){
    printf("Enter size: ");
    scanf("%d",&sizeA);
    printf("Enter data: ");
    for(int i=0; i<sizeA; i++){
        scanf("%d",&A[i]);
    }
}

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        for(; j>=0 && arr[j] > key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
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
    insertionSort(A,sizeA);
    printf("\nArray After Sorting: ");
    printArr(A,sizeA);
}