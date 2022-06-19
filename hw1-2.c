#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;

int swapInts(intptr a, intptr b){

  int temp;
  temp = *(a);
  *(a) = *(b);
  *(b) = temp;
  return 0;
}

int main(){

  intptr x;
  intptr y;
  x = (intptr) malloc(sizeof(int));
  y = (intptr) malloc(sizeof(int));
  *x = 12345;
  *y = 54321;
  
  printf("*x = %d\n",*x);
  printf("*y = %d\n",*y);

  swapInts(x, y);
  
  printf("*x = %d\n",*x);
  printf("*y = %d\n",*y);

  return 0;
}
