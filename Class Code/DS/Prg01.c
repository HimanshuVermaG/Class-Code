// Q. Find the smallest and largest element from the given array? 
#include<stdio.h>
void main()
{
    int ar[50],n,min,max;
    printf("Enter no of elements=");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }
    min=ar[0];
    for (int j = 1; j < n; j++)
    {
        if (min>ar[j])
        min=ar[j];
    }
    printf("Min value %d\t",min);
    max=ar[0];
    for (int j = 1; j < n; j++)
    {
        if (max<ar[j])
        max=ar[j];
    }
    printf("Max value %d\t",max);
}
