// Q. Radix Sort
#include<stdio.h>

int get_max(int arr[],int n)
{
    int max=arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        
    }
    return max;
    
}
void counting_sort(int arr[],int size,int place)
{
    int output[size+1];
    int max = (arr[0]/place)%10;
    for (int i = 0; i < size; i++)
    {
        if (((arr[0]/place)%10)>max)
        {
            max = arr[i];
        }
        
    }
    int count[max+1];
    for (int i = 0; i < max; ++i)       
    {
        count[i]=0;
    }
    for (int i = 0; i < size; i++)
    {
        count[(arr[i]/place)%10]++;
    }
    for (int i = 0; i < 9; i++)
    {
        count [i] +=count[i-1];
    }
    for (int i = size - 1; i >=0 ; i--)
    {
        output[count[(arr[i]/place)%10]-1] = arr[i];
        count[(arr[i]/place)%10]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i]=output[i];
    }
                
    
    
}
void radix_sort(int arr[],int size)
{
    int max = get_max(arr,size);
    for (int place = 1; max/place > 0; place*=10)
    {
        counting_sort(arr,size,place);
    }
    
}
void print_arr(int A[],int size)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");    
}

int main()
{
    int arr[] = {12,11,13,5,6,7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("Given arr is:\n");
    print_arr(arr,arr_size);
    printf("\nSorted arr is:\n");
    radix_sort(arr,arr_size);
    print_arr(arr,arr_size);
    return 0;
}