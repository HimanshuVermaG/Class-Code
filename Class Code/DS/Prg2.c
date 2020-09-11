// Q. Insert an element into the given array at
// @ 1st lacation , @end location, @given location
#include<stdio.h>
void main()
{
    int a[10]={},k,n,item=0;
    printf("Insert element:");
    scanf("%d",&n);
    printf("Which position: ");
    scanf("%d",&k);
    for (int i = 0; i < n; i++)   
    {
        printf("%d",a[i]);

    }
    for (int i = n; i >= k; i--)
    {
        a[i] = a[i - 1]; 
    }
    a[k-1] = item;
    for (int i = 0; i < n; i++)
    { 
        printf("%d ", a[i]);
    }
    
}