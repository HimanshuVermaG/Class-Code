#include <stdio.h> 
  
void validsubset(int arr1[], int arr2[]) 
{
    for (int i = 0; i <1; i++) 
        for (int j = 0; j < 1; j++)
            if(arr1[i]<=arr2[j])
                printf("Proper Subset");
            else
                printf("Improper Subset");
} 
  
int main() 
{ 
    int arr1[] = { 1, 2, 3 };
    int arr2[] = {1, 4, 2, 3 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
    validsubset(arr1, arr2); 
    return 0; 
} 