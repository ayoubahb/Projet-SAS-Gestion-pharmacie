#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){

  int f0 = 0,f1 = 1;
  int n,i;
  int fn,fn1,fn2;
  do{
  printf("Veuillez enter le nombre de suite de fibonachi (2 ou superieur): ");
  scanf("%d",&n);
  }while(n<2);
  printf("F[0] = 0\n");
  printf("F[1] = 1\n");
  fn1 = f1;
  fn2 = f0;
  for(i=2;i<=n;i++){
    fn = fn1 +fn2;
    fn2 = fn1;
    fn1 = fn;
    printf("F[%d] = %d\n",i,fn);
  }
  return 0;
}
