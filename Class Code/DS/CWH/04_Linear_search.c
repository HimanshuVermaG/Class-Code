#include<stdio.h>

int linear_search(int arr[],int size,int element)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
        {    
            printf("Element %d found at location: %d",element,i+1);
            return 1;
        }    
    }
    printf("Element %d not found!",element);
    
}

void main ()
{
   int arr[] = {1,2,3,4,5,6,74,8,9,7,45,75,54};
   int size = sizeof(arr)/sizeof(int);
   linear_search(arr,size,2);

}