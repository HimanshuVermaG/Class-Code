#include <stdio.h>
#define size 5

void initiate(int arr[][size]){
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            arr[i][j]=0;
        }
    }
}

void addEdge(int arr[][size], int src, int dest){
    arr[src][dest]=1;
}

void printAdjMtrx(int arr[][size]){
    printf("\n");
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int a[size][size];
    initiate(a);
    addEdge(a,0,1);
    addEdge(a,0,2);
    addEdge(a,0,3);
    addEdge(a,1,3);
    addEdge(a,1,4);
    addEdge(a,2,3);
    addEdge(a,3,4);
    printAdjMtrx(a);
}