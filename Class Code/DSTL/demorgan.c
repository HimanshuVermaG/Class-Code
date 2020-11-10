#include <stdio.h>
#include <conio.h>
void main()
{
    int a[2][2][2], b[2][2][2];
    int i, j,k;
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            for ( k = 0; k <= 1; k++)
            {
                a[i][j][k] = !(i || j || k);
                b[i][j][k] = (!i && !j && !k);
            }
            
        }
    }

    printf("\nThe truth table for Left Hand Side is\n");
    printf("   A    B     C    A&&B\n");
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            for ( k = 0; k <=1; k++)
            {
                printf("   %d    %d     %d    %d\n", i, j,k, a[i][j][k]);
            }
            
            
        }
    }
    printf("\nThe truth table for Right Hand Side is\n");
    printf("   A    B     C    A&&B\n");
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            for ( k = 0; k <=1; k++)
            {
                printf("   %d    %d     %d    %d\n", i, j,k, b[i][j][k]);
            }
            
            
        }
    }
    printf("\nHence Both Side Are Equal\n");

}
