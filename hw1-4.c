#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;
typedef int** intptrptr;

typedef struct nug{
  int val;
  struct nug* next;
} nug;

int findNthElement(struct nug* head, int n){

  nug* x;
  x = NULL;
  x = head;

  for (int i = 0; i < n; i++){
    x = x->next;
  }
  
  printf("%d\n",(*x).val);
  
  return 0;
}

int main(){

  printf("Hw1-4\n");
  
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
  
  findNthElement(head, 2);
  
  return 0;
}
