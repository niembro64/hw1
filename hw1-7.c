#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int* intptr;

typedef struct node{
  int val;
  struct node* next;
  struct node* prev;
} node;

node** reverse(node** head){

  if (head == NULL){
    return head;
  }

  node* temp;
  while ((*head)->next != NULL){
    temp = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev = temp;
    (*head) = (*head)->prev;
  }
    temp = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev = temp;
  
  return head;
}

int main(){

  printf("Hw1-7 Program\n");

  struct node* head = NULL;
  struct node** headDP = NULL;
  headDP = malloc(sizeof(node*));
  head = malloc(sizeof(node));

  *headDP = head;
  
  head->prev = NULL;
  head->val = 11;
  head->next = malloc(sizeof(node));

  head->next->prev = head;
  head->next->val = 22;
  head->next->next = malloc(sizeof(node));

  head->next->next->prev = head->next;
  head->next->next->val = 33;
  head->next->next->next = malloc(sizeof(node));

  head->next->next->next->prev = head->next->next;
  head->next->next->next->val = 44;
  head->next->next->next->next = NULL;

  printf("%d ",(*headDP)->val);
  printf("%d ",(*headDP)->next->val);
  printf("%d ",(*headDP)->next->next->val);
  printf("%d ",(*headDP)->next->next->next->val);
  printf("\n");

  headDP = reverse(headDP);

  printf("%d ",(*headDP)->val);
  printf("%d ",(*headDP)->next->val);
  printf("%d ",(*headDP)->next->next->val);
  printf("%d ",(*headDP)->next->next->next->val);
  printf("\n");

return 0;
}
