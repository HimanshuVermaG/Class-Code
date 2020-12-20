#include<stdio.h>

int binary_search(int arr[],int size,int element)
{
    int low,mid,high;
    low = 0;
    high = size-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==element)
        {
            printf("Element %d found at location: %d",element,mid+1);
            return mid;
        }
        else if(arr[mid]<element)
        {
            low = mid+1;
        }
        else
        {
            high=mid-1;
        }

    }
    printf("Element %d not found!",element);
    return -1;

}

void main ()
{
   int arr[] = {1,2,3,4,5,6,7};
   int size = sizeof(arr)/sizeof(int);
   binary_search(arr,size,30);

}