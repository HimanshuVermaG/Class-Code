// Q. Selection Sort
#include<stdio.h>
void main()
{
    int n,a[10],temp,j,i,min;
    printf("Enter the no elements = ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d",&a[j]);
    }
    for (int i = 0; i <= n; i++)
    {
        min=i;
        for (int j = i+1; j <= n-1; j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
            temp = a[i];
            a[i]=a[min];
            a[min]=temp;

        }
        
    }
    printf("Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",a[i]);
}