// Q. Insertion Sort
#include<stdio.h>

void main()
{
    int n,a[10],j,i,key;
    printf("Enter the no elements = ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d",&a[j]);
    }
    for (int i = 1; i < n; i++)
    {
        key=a[i];
        j=i-1;
        while (key < a[j] && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
        
    }
    printf("Sorted elements: ");
    for(i=0;i<n;i++)
      printf(" %d",a[i]);
}