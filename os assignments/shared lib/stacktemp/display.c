#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int capacity;
	int *array;
	int top;
};
typedef struct stack stack;
void display_stack(stack *S)
{
	int temp = S->top;	
	if(temp == -1)
	{
		printf("Stack is empty\n");
		return;	
	}
	printf("Stack elements are:\n");	
	while(temp != -1)
	{
		printf("%d\n",S->array[temp--]);
	}
}	
