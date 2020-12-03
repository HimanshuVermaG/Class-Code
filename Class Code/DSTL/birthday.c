#include<stdio.h>

void main ()
{
    int n;
    float p=1;
    printf("Enter number of people in a room: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        p=p*(365-i)/365;
    }
    p=1-p;
    p=p*100;
    printf("Percentage of having birthday on same day: %.2f per",p);
}