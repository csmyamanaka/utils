#pragma once

#include <stdlib.h>

typedef struct fNode{
  struct fNode* next;
  struct fNode* prev;
  float val;
}fNode;

typedef struct fLList{
  fNode* first;
  fNode* last;
  int n;
}fLList;

fLList* initfLList(){
  fLList* ret = malloc(sizeof(fLList));
  ret->first = NULL;
  ret->last = NULL;
  ret->n = 0;
  return ret;
}

int appendfll(fLList* a0, float a1){
  fNode* temp = malloc(sizeof(fNode));
  temp->val = a1;
  temp->next = NULL;
  temp->prev = a0->last;
  if(a0->n == 0) a0->first = temp;
  else a0->last->next = temp;
  a0->n = a0->n + 1;
  a0->last = temp;
  return 0;
}

int prependfll(fLList* a0, float a1){
  fNode* temp = malloc(sizeof(fNode));
  temp->val = a1;
  temp->next = a0->first;
  temp->prev = NULL;
  if(a0->n == 0) a0->last = temp;
  else a0->first->prev = temp;
  a0->n = a0->n + 1;
  a0->first = temp;
  return 0;
}

int rmFirst(fLList* a0){
  if(a0->n == 0) return 0;
  else if(a0->n == 1){
    free(a0->first);
    a0->first = NULL;
    a0->last = NULL;
  }else{
    fNode* temp = a0->first;
    a0->first = temp->next;
    a0->first->prev = NULL;
    temp->next = NULL;
    free(temp);
  }
  a0->n = a0->n - 1;
  return 0;
}

int rmLast(fLList* a0){
  if(a0->n == 0) return 0;
  else if(a0->n == 1){
    free(a0->first);
    a0->first = NULL;
    a0->last = NULL;
  }else{
    fNode* temp = a0->last;
    a0->last = temp->prev;
    a0->last->next = NULL;
    temp->prev = NULL;
    free(temp);
  }
  a0->n = a0->n - 1;
  return 0;
}

int freefLList(fLList* a0){
  while(a0->n > 0) rmLast(a0);
  return 0;
}
