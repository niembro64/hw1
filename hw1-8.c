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

int isPalyndrome(node* head){
  // 1 is paly 0 if not
  if (head == NULL){
    return 1;// i mean symantics?
  }

  node* head2;
  head2 = malloc(sizeof(node));

  node* h1p;
  node* h2p;
  h1p = head;
  h2p = head2;
  h2p->prev = NULL;
  h2p->next = NULL;
  h2p->val = h1p->val;

  while (h1p->next != NULL){
    h1p = h1p->next;
    h2p->next = malloc(sizeof(node));
    h2p->next->prev = h2p;
    h2p->next->next = NULL;
    h2p =  h2p->next;
    h2p->val = h1p->val;
  }

  node** head1DP;
  node** head2DP;
  head1DP = &head;
  head2DP = &head2;
  head2DP = reverse(head2DP);

  int x = 0; // track number of non-similarities between two linked lists
  
  // check reversed vs og 
  while((*head1DP) != NULL){
    if((*head1DP)->val != (*head2DP)->val){
      x++;
    }
    (*head1DP) = (*head1DP)->next;
    (*head2DP) = (*head2DP)->next;
  }
  
  return ((x>0)?0:1); // x=0 is palyndrome
}

int main(){

  printf("Hw1-8 Program\n");

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
  head->next->next->val = 22;
  head->next->next->next = malloc(sizeof(node));

  head->next->next->next->prev = head->next->next;
  head->next->next->next->val = 11;
  head->next->next->next->next = NULL;

  printf("%d ",(*headDP)->val);
  printf("%d ",(*headDP)->next->val);
  printf("%d ",(*headDP)->next->next->val);
  printf("%d ",(*headDP)->next->next->next->val);
  printf("\n");

  int paly;
  paly = isPalyndrome(head);

  printf("Is Paly? : %d\n",paly);

  // non-paly
  
  struct node* headb = NULL;
  struct node** headDPb = NULL;
  headDPb = malloc(sizeof(node*));
  headb = malloc(sizeof(node));

  *headDPb = headb;
  
  headb->prev = NULL;
  headb->val = 11;
  headb->next = malloc(sizeof(node));

  headb->next->prev = headb;
  headb->next->val = 99;
  headb->next->next = malloc(sizeof(node));

  headb->next->next->prev = headb->next;
  headb->next->next->val = 22;
  headb->next->next->next = malloc(sizeof(node));

  headb->next->next->next->prev = headb->next->next;
  headb->next->next->next->val = 11;
  headb->next->next->next->next = NULL;

  printf("%d ",(*headDPb)->val);
  printf("%d ",(*headDPb)->next->val);
  printf("%d ",(*headDPb)->next->next->val);
  printf("%d ",(*headDPb)->next->next->next->val);
  printf("\n");

  int palyb;
  palyb = isPalyndrome(headb);

  printf("Is Paly? : %d\n",palyb);


  
return 0;
}
