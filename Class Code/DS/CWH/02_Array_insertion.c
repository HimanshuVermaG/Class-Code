#include<stdio.h>

// Traversal
void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
// Insertion in array
int arrayInsertion(int arr[],int size,int index,int element,int capacity)
{
    if(size>=capacity)
    {
        printf("Array is Full!");
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]= arr[i];
    }
    arr[index]= element;
    printf("\nInserted element successfully!\n");
    return 1;
    
}

int main ()
{
    int arr[100] = {1,2,3,4,5};
    int size = 5,index= 3,element = 45,capacity = 100;
    display(arr,size);
    arrayInsertion(arr,size,index,element,capacity);
    size +=1;
    display(arr,size);
}
