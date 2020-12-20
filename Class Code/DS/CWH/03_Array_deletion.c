#include<stdio.h>

// Traversal
void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
// Deletion in array
int arrayDeletion(int arr[],int size,int index)
{
 
    for (int i = index; i < size-1 ; i++)
    {
        arr[i]= arr[i+1];
    }
    printf("\nDeleted element successfully!\n");
    return 1;
    
}

int main ()
{
    int arr[10] = {1,2,3,4,5};
    int size = 5,index= 2,capacity = 10;
    display(arr,size);
    arrayDeletion(arr,size,index);
    size -=1;

    display(arr,size);
    return 0;
}
