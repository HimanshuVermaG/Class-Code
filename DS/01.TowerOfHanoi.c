#include <stdio.h> 
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, to_rod, aux_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 
    int num;
    printf("Enter No. Of Disks to be Operated On:");
    scanf("%d",&num);
    towerOfHanoi(num, 'A', 'B', 'C'); 
    return 0; 
}