#include<stdio.h>

int BinarySearch(int arr[], int start, int last, int val){
    if(last >= start){
        int mid = start + (last - start)/2;

        if(arr[mid] == val){
            return mid;
        }

        if(arr[mid]>val){
            return BinarySearch(arr, start, mid - 1, val);
        }

        return BinarySearch(arr, mid + 1, last, val);
    }

    return -1;
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

    int result = BinarySearch(arr,0,size-1,data);

    if(result == -1){
        printf("\n%d NOT FOUND",data);
    }
    else{
        printf("\n%d FOUND @%d INDEX",data, result);
    }
}