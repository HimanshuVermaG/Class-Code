#include<stdio.h>

void insert(int arr[], int size, int val, int pos){
    if(pos > size){
        printf("\n!! Invalid Pos. !!");
        return;
    }
    if(pos == size){
        arr[pos] = val;

    }
    for(int i=0; i>pos; i--){
        arr[size-i] = arr[size-i-1];
    }
    arr[pos] = val;


    printf("\nThe Array After insertion: \n");
    for(int i=0; i<size+1; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void isThere(int ar[], int size, int val){
    for(int i=0; i<size; i++){
        if(ar[i] == val){
            printf("\n%d Found At %dth Index !\n", val,i);
            return;
        }
    }
    printf("\n!! %d Not Found !!",val);
}

int delete(int arr[], int size, int val){ 
    int i;
    for (i=0; i<size; i++){
       if (arr[i] == val){
            break; 
        }
    } 
       
    if (i < size){ 
        size--; 
        for (int j=i; j<size; j++) 
            arr[j] = arr[j+1]; 
    } 
   return size; 
}

int main(){
    int val, size,pos, ar[100];
    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("\nEnter Element of Array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &ar[i]);
    }

    printf("\nThe Array is: \n");
    for(int i=0; i<size; i++){
        printf("%d ",ar[i]);
    }
    printf("\n");

    printf("\nEnter Element to Be Inserted: ");
    scanf("%d", &val);

    printf("Enter Pos. to Enter At: ");
    scanf("%d", &pos);
    insert(ar,size,val,pos); 

    printf("\nEnter Element to Be Searched: ");
    scanf("%d", &val);
    isThere(ar, size, val); 

    printf("\nEnter Element to Delete: ");
    scanf("%d",&val);
    size = delete(ar,size,val);

    printf("\nThe Array is: \n");
    for(int i=0; i<size; i++){
        printf("%d ",ar[i]);
    }
    printf("\n");

}