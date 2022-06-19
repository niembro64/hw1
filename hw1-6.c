#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;
typedef int** intptrptr;

typedef struct nug{
  int val;
  struct nug* next;
} nug;

int findNthToLastElement(struct nug* head, int n){

  int numOfNodes = 1;
  nug* countNug;
  countNug = head;
  while (countNug->next != NULL){
    numOfNodes++;
    countNug = countNug->next;
  }

  // printf("numOfNodes = %d\n", numOfNodes);

  nug* x;
  x = NULL;
  x = head;
  for (int i = 1; i < (numOfNodes-(n-1)); i++){
    x = x->next;
  }
  
  printf("%d\n",x->val);
  
  return 0;
}

int main(){

  printf("Hw1-6\n");
  nug* head = NULL;

  head = malloc(sizeof(nug));
  head->val = 10;
  head->next = malloc(sizeof(nug));
  head->next->val = 20;
  head->next->next = malloc(sizeof(nug));
  head->next->next->val = 30;
  head->next->next->next = malloc(sizeof(nug));
  head->next->next->next->val = 40;
  head->next->next->next->next = NULL;

  printf("%d ",head->val);
  printf("%d ",head->next->val);
  printf("%d ",head->next->next->val);
  printf("%d ",head->next->next->next->val);
  printf("\n");
  
  findNthToLastElement(head, 2);
  findNthToLastElement(head, 1);
  findNthToLastElement(head, 4);
  
  return 0;
}
