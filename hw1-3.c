#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;
typedef int** intptrptr;

int swapPtrs(intptrptr x, intptrptr y){

  intptrptr temp;
  temp = (intptrptr) malloc(sizeof(intptr));
  *temp = *x;
  *x = *y;
  *y = *temp;
  return 0;
}

int main(){

  intptr a;
  intptr b;
  a = (intptr) malloc(sizeof(int));
  b = (intptr) malloc(sizeof(int));
  *a = 123456;
  *b = 654321;
  
  intptrptr alpha;
  intptrptr beta;
  alpha = (intptrptr) malloc(sizeof(intptr));
  beta = (intptrptr) malloc(sizeof(intptr));
  alpha = &a;
  beta = &b;
  
  printf("**alpha = %d\n", **alpha);
  printf("**beta = %d\n", **beta);

  swapPtrs(alpha, beta);

  printf("**alpha = %d\n", **alpha);
  printf("**beta = %d\n", **beta);
  
  
  return 0;
} 
