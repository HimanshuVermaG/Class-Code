#include<stdio.h>

void Linearsearch(int arr[], int size, int val){
    for(int i=0; i<size; i++){
        if(arr[i] == val){
            printf("\n!! %d FOUND @%d INDEX !!",val,i);
            return;
        }
    }
    printf("\n!! %d NOT FOUND !!",val);   
}

void printArr(int ar[], int size){
    printf("\nArray is: ");
    for(int i=0; i<size; i++){
        printf("%d ",ar[i]);
    }
}

int main(){
    int size,data;
    printf("\nEnter size of Array: ");

    scanf("%d",&size);
    int arr[size];

    printf("\nEnter Elements of Array: ");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }

    printArr(arr,size);

    printf("\nEnter Value to Search: ");
    scanf("%d",&data);

    Linearsearch(arr,size,data);
}