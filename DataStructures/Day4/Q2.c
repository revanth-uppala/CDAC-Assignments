/*Write a program to Implement Evaluation of postfix expression.*/
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int top,capacity;
	int *arr;
};
typedef struct stack stack;
int IsEmpty(stack *S)
{
	return S->top == -1;
}


void push(stack *S,int value)
{
	if(S->top == S->capacity - 1)
	{
		printf("Cannot insert.Stack overflow\n");	
	}
	S->top++;
	
	S->arr[S->top] = value;
}
int pop(stack *S)
{
	if(S->top == -1)
	{
		printf("Cannot pop.Stack underflow\n");
		return 255;	
	}
	return S->arr[S->top--];
}


int main()
{
	int i,right,left;	
	char str[20],data;
	stack *S;
	S = (stack*)malloc(sizeof(stack));
	S->capacity = 20;
	S->top = -1;	
	S->arr = (int*)malloc(sizeof(char)*(S->capacity));
	printf("Enter any Postfix expression \n");
	scanf("%s",str);
	printf("Entered expression is %s\n",str);
	for(i = 0 ; str[i] != '\0' ; i++)
	{
		
				
		if((str[i] != '+') && (str[i] != '-') && (str[i] != '*') && (str[i] != '/'))
		{
			push(S,str[i]);
		}
		if((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/'))
		{
			right = pop(S)-'0';
			left = pop(S)-'0' ;
			switch(str[i])
			{
				case '+':
					push(S,'0' + left+right);
					break;
				case '-':
					push(S,'0' + left-right);
					break;
				case '*':
					push(S,'0' + left*right);
					break;
				case '/':
					push(S,'0' + left/right);
					break;
			}
				
		}
	}
	
	printf("\nResult = %d\n",pop(S)-'0');
	return 0;
}
		
				
