// Q. Search an element from given array?? Linear Search:
#include<stdio.h>
void main()
{
    int ar[50],n,find,found,i;
    printf("Enter no of elements=");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d", &find);
    found = 0; 
    
    for(i=0; i<n; i++)
    {
        if(ar[i] == find)
        {
            found = 1;
            break;
        }
    }
    if(found == 1)
    {
        printf("\n%d is found at position %d", find, i + 1);
    }
    else
    {
        printf("\n%d is not found in the array", find);
    }
    

}