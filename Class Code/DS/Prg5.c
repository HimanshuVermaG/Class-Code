#include<stdio.h>
void add(int m[3][3],int n[3][3])
{
    int i,j,k,sum,c[3][3];
    // Multiply both matrix a & b
    for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                int sum=0;
                for (int k = 0; k < 3; k++)
                {
                    sum+= m[i][j]+n[i][j];
                }
                c[i][j]=sum;
            }   
        }
    printf("Addition of two matrix is:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }    
    
}
int main()
{
    int i,j,a[3][3],b[3][3];
    // Print first matrix
    printf("Enter first matrix is;\n");
    for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                scanf("%d",&a[i][j]);
            }
            printf("\n");
        }
    printf("Entered second matrix is;\n");
    for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                scanf("%d",&b[i][j]);
            }
            printf("\n");
        }
    printf("Entered first matrix is;\n");
    for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
    printf("Entered second matrix is;\n");
    for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                printf("%d\t",b[i][j]);
            }
            printf("\n");
        }
    add(a,b);
}   