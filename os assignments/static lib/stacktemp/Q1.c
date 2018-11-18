/*Create a Stack using array implementation with functions: push(),
pop and tos. Write a function display_stack to print all elements*/
#include<stdio.h>
#include<stdlib.h>
#include "header.h"

/*void display_stack(stack *S)
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
void push(stack *S,int value)
{
	if(S->top == S->capacity - 1)
	{
		printf("Cannot insert.Stack overflow\n");	
	}
	S->top++;
	
	S->array[S->top] = value;
}
int pop(stack *S)
{
	if(S->top == -1)
	{
		printf("Cannot pop.Stack underflow\n");
		return -999;	
	}
	return S->array[S->top--];
}
int tos(stack *S)
{
	if(S->top == -1)
	{
		printf("Stack is empty\n");
		return -999;	
	}	
	return S->array[S->top];
}*/
int main()
{
	stack *S;
	S = (stack*)malloc(sizeof(stack));	
	S->capacity = 10;	
	S->top = -1;
	S->array = (int*)malloc(sizeof(int)*(S->capacity));
	int data,ch;
	while(1)
	{	
		printf("Enter choice:\n1.Push\n2.Pop\n3.TOS\n4.Display stack\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter data to push onto stack\n");
				scanf("%d",&data);
				push(S,data);
				tos(S);
				break;
			case 2: data = pop(S);
				if(data != -999)
				{
					printf("Popped value = %d\n",data);
				}
				break;
			case 3:data = tos(S);
				if(data != -999)
				{
					printf("Top of Stack = %d\n",data);
				}
				break;
			case 4: display_stack(S);
				break;			
			case 5: exit(1);
		}
	}
	return 0;
}
	
	
