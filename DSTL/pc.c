#include<stdio.h>
 
double factorial(int n){
  int i;
  double fact=1;
  for(i=n;i>=1;i--){
    fact=fact*i;
  }
  return fact;
}
 
int main(){
  int n,r,choice;
  printf("\n\nType 1 for Permutation and 2 for Combination\n");
  scanf("%d",&choice);
  if(choice==1){
    printf("Enter n and r for nPr\n");
    scanf("%d %d",&n,&r);
    if(r>n){
      printf("Sorry! r should be smaller than n\n");
      return 0;
    }
    printf("The permutation (%dP%d)= %f\n",n,r,factorial(n)/factorial(n-r));
  }else if(choice==2){
    printf("Enter n and r for nCr\n");
    scanf("%d %d",&n,&r);
    if(r>n){
      printf("r should be smaller than n\n");
      return 0;
    }
    printf("The combination (%dC%d)= %f\n",n,r,factorial(n)/(factorial(n-r)*factorial(r)));
  }
  else{
    printf("\nPlease enter a valid choice!\n");
  }
}