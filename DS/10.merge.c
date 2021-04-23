#include<stdio.h>
int A[100];
int sizeA = 0;

void merge(int arr[], int start, int end){
    int size3 = end - start + 1;
    int mid = (start + end)/2;
    int output[size3];
    int i = start,j = mid+1, k=0;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            output[k] = arr[i];
            i++, k++;
        }
        else if(arr[i]>=arr[j]){
            output[k] = arr[j];
            j++, k++;
        }
    } 

    while(i<=mid){
        output[k] = arr[i];
        i++, k++;
    }

    while(j<=end){
        output[k] = arr[j];
        j++, k++;
    }

    for(k=0; k<size3;k++){
        arr[k + start] = output[k];
    }
}

void helpsort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    helpsort(arr,start,mid);
    helpsort(arr,mid+1,end);
    merge(arr,start,end);
}

void mergeSort(int arr[], int size){
    helpsort(arr, 0, size-1);
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
    mergeSort(A,sizeA);
    printf("\nArray After Sorting: ");
    printArr(A,sizeA);
}