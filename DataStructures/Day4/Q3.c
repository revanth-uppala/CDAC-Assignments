/*Balancing parentheses in an Arithmetic Expression.*/
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int top,capacity;
	char *arr;
};
typedef struct stack stack;
int IsEmpty(stack *S)
{
	return S->top == -1;
}

void push(stack *S,char value)
{
	if(S->top == S->capacity - 1)
	{
		printf("Cannot insert.Stack overflow\n");	
	}
	S->top++;
	
	S->arr[S->top] = value;
}
char pop(stack *S)
{
	if(S->top == -1)
	{
		printf("Cannot pop.Stack underflow\n");
		return 255;	
	}
	return S->arr[S->top--];
}
char tos(stack *S)
{
	if(S->top == -1)
	{
		printf("Stack is empty\n");
		return 255;	
	}	
	return S->arr[S->top];
}

int main()
{
	int i;	
	char str[20],data;
	stack *S;
	S = (stack*)malloc(sizeof(stack));
	S->capacity = 20;
	S->top = -1;	
	S->arr = (char*)malloc(sizeof(char)*(S->capacity));
	printf("Enter any expression with parenthesis\n");
	scanf("%s",str);
	printf("Entered expression is %s\n",str);
	for(i = 0 ; str[i] != '\0' ; i++)
	{
		if((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
		{
			push(S,str[i]);
		}
		if((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
		{
			data = pop(S);
			
			if((data == '(' && str[i] == ')') || (data == '{' && str[i] == '}') || (data == '[' && str[i] == ']'))
			{
				continue;
			}
			else
			{
				printf("Parenthesis not matching\n");
				exit(1);
			}
		}
	}
	if(!IsEmpty(S))
	{
		printf("Parenthesis not matching\n");
		exit(1);
	}
	else
	{
		printf("Parenthesis matching\n");
	}
	return 0;
}
		
				
