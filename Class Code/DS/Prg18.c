// Q. Bubble Sort
#include<stdio.h>

void main()
{
    int n,a[10],temp,j,i;
    printf("Enter the no elements = ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d",&a[j]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }
        
    }
    printf("Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",a[i]);
}