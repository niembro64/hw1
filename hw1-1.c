#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;

int set(intptr a, int val){

  *(a) = val;
  return 0;
}

int main(){

  intptr x;
  x = (intptr) malloc(sizeof(int));
  int y = 12345;

  printf("y = %d\n",y);
  printf("x = %d\n",x);
  printf("*(x) = %d\n",*(x));

  set(x, y);

  printf("y = %d\n",y);
  printf("x = %d\n",x);
  printf("*(x) = %d\n",*(x));

  return 0;
}
