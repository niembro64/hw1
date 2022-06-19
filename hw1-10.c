#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;

typedef struct node{
  int val;
  struct node* p;
  struct node* rc;
  struct node* lc;
} node;

void nr_preorder_print(node* p){

  // push();
  // pop();
  // nope();
}

int main(){

  printf("Hw1-10 Program\n");

  struct node* head = NULL;
  struct node** headDP = NULL;
  headDP = malloc(sizeof(node*));
  head = malloc(sizeof(node));

  *headDP = head;

  // creating nodes BST
  head->p = NULL;
  head->val = 100;
  head->lc = malloc(sizeof(node));
  head->rc = malloc(sizeof(node));

  head->lc->p = head;
  head->lc->val = 75;
  head->lc->lc = malloc(sizeof(node));
  head->lc->rc = NULL;
  
  head->lc->lc->p = head->lc;
  head->lc->lc->val = 50;
  head->lc->lc->lc = malloc(sizeof(node));
  head->lc->lc->rc = NULL;

  head->lc->lc->lc->p = head->lc->lc;
  head->lc->lc->lc->val = 25;
  head->lc->lc->lc->lc = NULL;
  head->lc->lc->lc->rc = NULL;

  head->rc->p = head;
  head->rc->val = 125;
  head->rc->lc = NULL;
  head->rc->rc = malloc(sizeof(node));
  
  head->rc->rc->p = head->rc;
  head->rc->rc->val = 150;
  head->rc->rc->lc = NULL;
  head->rc->rc->rc = NULL;

  // standard printing test PRINT IN ORDER
  printf("%d ",head->lc->lc->lc->val);
  printf("%d ",head->lc->lc->val);
  printf("%d ",head->lc->val);
  printf("%d ",head->val);
  printf("%d ",head->rc->val);
  printf("%d ",head->rc->rc->val);

  printf("\n");

  // recursive print
  nr_preorder_print(head);

return 0;
}
