#include<stdio.h>
int A[100];
int sizeA = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    int temp = 0, count = 0;
    for(int i = start+1; i<=end; i++){
        if(arr[i]<=arr[start])
            count++;
    }

    int pivot = start + count;

    swap(&arr[pivot],&arr[start]);

    int i=start,j=end;

    while(i<pivot && j>pivot){
        if(arr[i]<=arr[pivot]){
            i++;
        }
        else if(arr[j]>arr[pivot]){
            j--;
        }
        else{
            swap(&arr[i],&arr[j]);
        }
    }
    return pivot;
}

void qs(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int pivot = partition(arr,start,end);
    qs(arr,start,pivot-1);
    qs(arr,pivot+1,end);
}

void quickSort(int arr[], int size){
    qs(arr, 0, size -1);
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
    quickSort(A,sizeA);
    printf("\nArray After Sorting: ");
    printArr(A,sizeA);
}