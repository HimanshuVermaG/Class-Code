#include<stdio.h>
int main()
{
    int values[6];
    printf("Enter 5 integers : ");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d\n", &values[i]);
    }
    printf("Displaying Integers:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", values[i]);
    }
    
}
