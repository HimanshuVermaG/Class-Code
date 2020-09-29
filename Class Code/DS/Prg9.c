#include<stdio.h>
void addition(int a[3][3],int b[3][3])
{
   int m[3][3],i,j;
   for ( i = 0; i < 3; i++)
   {
       for ( j = 0; j < 3; j++)
       {
            m[i][j]=a[i][j]+b[i][j];
       }   
   }
   printf("Addition of Matrix is:\n");
   for ( i = 0; i < 3; i++)
   {
       for ( j = 0; j < 3; j++)
       {
            printf("%d",&m[i][j]);
       }
   }
   
}
void subtraction(int a[3][3],int b[3][3])
{
   int m[3][3],i,j;
   for ( i = 0; i < 3; i++)
   {
       for ( j = 0; j < 3; j++)
       {
            m[i][j]=a[i][j]-b[i][j];
       }   
   }
   printf("Addition of Matrix is:\n");
   for ( i = 0; i < 3; i++)
   {
       for ( j = 0; j < 3; j++)
       {
            printf("%d",&m[i][j]);
       }
   }
   
}
int main()
{   
    int  a[3][3],b[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter b[%d][%d]:",i,j);
            scanf("%d",&b[i][j]);
        }
        
    }
    addition(a,b);
    subtraction(a,b);
    
}