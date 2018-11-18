#include<stdio.h>
#include<stdlib.h>
#include "DS_lib.h"
int main()
{
  node *headLL = NULL;
  node *headDLL = NULL;
  stack *S = NULL;
  S = stackinit(S);
  int data = 5;
  headLL = insertbeg(headLL,data);
  insertbegDLL(data);
  push(S,data);
  display(headLL);
  displayDLL(headDLL);
  printf("%d",TOS(S));
  return 0;
}
