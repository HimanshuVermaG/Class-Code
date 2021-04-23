#include<stdio.h>
int A[100];
int sizeA = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size){
    int min_indx;
    for(int i=0; i<size-1; i++){
        min_indx = i;
        for(int j = i+1; j<size; j++){
            if(arr[j]<arr[min_indx]){
                min_indx = j;
            }
        }
        swap(&arr[min_indx],&arr[i]);
    }
}

void takeInput(){
    printf("Enter size: ");
    scanf("%d",&sizeA);
    printf("Enter data: ");
    for(int i=0; i<sizeA; i++){
        scanf("%d",&A[i]);
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
    selectionSort(A,sizeA);
    printf("\nArray After Sorting: ");
    printArr(A,sizeA);
}

