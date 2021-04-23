#include<stdio.h>
#define r 3
#define c 3

void addMat(int A[][c], int B[][c], int C[][c]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = A[i][j] + B[i][j]; 
        }
    }
}

void subMat(int A[][c], int B[][c], int C[][c]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = A[i][j] - B[i][j]; 
        }
    }
}

void multiplyMat(int A[][c], int B[][c], int C[][c]){    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = 0;
            for(int k=0; k<3; k++){
                C[i][j] += A[i][k] * B[k][i];
            }
        }
    }
}

void transMat(int A[][c], int C[][c]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            C[j][i] = A[i][j];
        }
    }
}

void rowSum(int A[][c]){
    int rsum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            rsum += A[i][j];
        }
        printf("\nSum of Row%d: %d",i,rsum);
    }
    printf("\n");
}

void colSum(int A[][c]){
    int csum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            csum += A[j][i];
        }
        printf("\nSum of Row%d: %d",i,csum);
    }
    printf("\n");
}

void printMat(int A[][c]){
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int A[r][c] = { {11, 22, 33}, 
                    {44, 55, 66}, 
                    {77, 88, 99}, 
                };

    int B[r][c] = { {10, 20, 30}, 
                    {40, 50, 60}, 
                    {70, 80, 90}, 
                };

    int C[r][c];

    printf("\nMatrix A: ");
    printMat(A);

    printf("\nSum of Rows of MatA: ");
    rowSum(A);
    printf("\nSum of Coloumns  of MatA: ");
    colSum(A);

    printf("\nMatrix B: ");
    printMat(B);

    printf("\nSum of Rows of MatB: ");
    rowSum(B);
    printf("\nSum of Coloumns  of MatB: ");
    colSum(B);

    printf("\nTranspose of MatA: ");
    transMat(A,C);
    printMat(C);

    printf("\nTranspose of MatB: ");
    transMat(B,C);
    printMat(C);

    printf("\nAddition of MatA & MatB: ");
    addMat(A,B,C);
    printMat(C);

    printf("\nSubtraction of MatA & MatB: ");
    subMat(A,B,C);
    printMat(C);

    printf("\nMultiplication of MatA & MatB: ");
    multiplyMat(A,B,C);
    printMat(C);

}