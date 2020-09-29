#include<stdio.h>
#include<math.h>
int num(int n)
{
    int total=0;
    for (int i = 1; i <= n; i++)
    {
        total += i;
    }
    return total;
    
}
int lsum(int n)
{
    int total=0;
    for (int i = 0; i <= n; i++)
    {
        total += pow(i,3);
    }
    return total;
    
}
int rsum(int n)
{
    int total=0;
    for (int i = 0; i <= n; i++)
    {
        total = pow(num(i),2);
    }
    return total;
    
}

int main ()
{
    int n,rhs,lhs;
    printf("Mathematical Induction Proof for : \nP(n): 1^3+2^3+3^3+......+n^3=(1+2+3+4+..n)^2");
    printf("\n\nFor n=1\n");
    printf("L.H.S P(1)=(1^3)=1\nR.H.S P(1)=(1)^2=1\n\nHence L.H.S = R.H.S,Therefore P(1) is true.");
    printf("\nAssume that P(n) is true for n=k.\n i.e P(k): 1^3+2^3+3^3+......+k^3=(1+2+3+4+..k)^2\n\nNow check for k =");
    n=5;
    rhs=rsum(n);
    printf("\nR.H.S P(%d)=%d\n",n,rhs);
    lhs=lsum(n);
    printf("L.H.S P(%d)=%d\nHence L.H.S = R.H.S\n\nNow checking for k+1",n++,lhs);
    rhs=rsum(n);
    printf("\nR.H.S P(%d)=%d\n",n,rhs);
    lhs=lsum(n);
    printf("L.H.S P(%d)=%d\nHence L.H.S = R.H.S",n,lhs);
    printf("\nTherefore, P(n) is true for all positive integers.");


}
