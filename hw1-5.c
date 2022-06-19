#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;

typedef struct node{
  int val;
  struct node* next;
} node;

node* removeNthElement(struct node* head, int n){
  if (n == 1){
    node * temp1;
    temp1 = head;
    head = temp1->next;
    free(temp1);
  }
  if (n > 1){
      node * q;
      node * p;

      p = head;
      q = head;
      for (int i = 1; i < (n-1); i++){//emn
	p = p->next;
      }
      q = p->next;
      p->next = q->next;
      free(q);
    }
  
  
   return head;
}
int main(){

  printf("Hw1-5 Program\n");

  struct node* head = NULL;
  head = malloc(sizeof(node));
  head->val = 16;
  head->next = malloc(sizeof(node));
  head->next->val = 22;
  head->next->next = malloc(sizeof(node));
  head->next->next->val = 33;
  head->next->next->next = malloc(sizeof(node));
  head->next->next->next->val = 44;
  head->next->next->next->next = NULL;

  printf("%d ",head->val);
  printf("%d ",head->next->val);
  printf("%d ",head->next->next->val);
  printf("%d ",head->next->next->next->val);
  printf("\n");

  head = removeNthElement(head, 1);

  printf("%d ",head->val);
  printf("%d ",head->next->val);
  printf("%d ",head->next->next->val);
  printf("\n");

  head = removeNthElement(head, 2);

  printf("%d ",head->val);
  printf("%d ",head->next->val);
  printf("\n");

return 0;
}
