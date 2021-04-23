#include<stdio.h>
int A[100];
int sizeA = 0;

int getMax(int arr[], int size) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < size; i++){
        if (arr[i] > mx) 
            mx = arr[i]; 
    } 
    return mx; 
} 

void countSort(int arr[], int size, int exp){
    int output[size]; 
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < size; i++){
        count[(arr[i] / exp) % 10]++;
    }
         
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
         
    for (i = size - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    for (i = 0; i < size; i++){
        arr[i] = output[i];
    }         
} 


void radixSort(int arr[], int size){
    int m = getMax(arr,size);
    for (int exp = 1; m/exp > 0; exp *=10){
        countSort(arr, size, exp);
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
    radixSort(A,sizeA);
    printf("\nArray After Sorting: ");
    printArr(A,sizeA);
}