#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int capacity;
	int *array;
	int top;
};
typedef struct stack stack;
int tos(stack *S)
{
	if(S->top == -1)
	{
		printf("Stack is empty\n");
		return -999;	
	}	
	return S->array[S->top];
}
