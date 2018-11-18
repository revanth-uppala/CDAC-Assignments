#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int capacity;
	int *array;
	int top;
};
typedef struct stack stack;
void push(stack *S,int value)
{
	if(S->top == S->capacity - 1)
	{
		printf("Cannot insert.Stack overflow\n");	
	}
	S->top++;
	
	S->array[S->top] = value;
}
