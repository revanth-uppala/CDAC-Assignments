#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 20
int pop_data;
struct stack
{
  int *arr,size,top,capacity;
};
typedef struct stack stack;
stack *stackinit(stack *S)
{
  S = (stack*)malloc(sizeof(stack));
  S->capacity = STACK_SIZE;
  S->arr = (int*)malloc(sizeof(int)*(S->capacity));
  S->top = -1;
  return S;
}
unsigned short IsEmpty(stack *S)
{
  return S->size == 0;
}
unsigned short IsFull(stack *S)
{
  return S->size == S->capacity;
}
stack *push(stack *S,int val)
{
  if(!IsFull(S))
  {
    S->size++;
    S->top++;
    S->arr[S->top] = val;
    return S;
  }
  else
  {
    printf("Stack Overflow\n");
    return S;
  }
}
stack *pop(stack *S)
{
  if(!IsEmpty(S))
  {
    S->size--;
    pop_data = S->arr[S->top--];
    return S;
  }
  else
  {
    printf("Stack Underflow\n");
    return S;
  }
}
int TOS(stack *S)
{
  if(!IsEmpty(S))
  return S->arr[S->top];
  else
  return -999;
}
void displaystack(stack *S)
{
  if(!IsEmpty(S))
  {
    int i;
    for(i = S->top ; i >= 0 ; i --)
    {
      printf("|%d|\n",S->arr[i]);
    }
    printf(" __\n");
  }
  else
  {
    printf("Stack is empty\n");
  }
}
