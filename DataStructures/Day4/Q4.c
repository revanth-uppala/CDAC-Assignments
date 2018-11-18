/*Write a function is_palindrome which takes a string as argument and
returns 1 if True,0 if False.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
	int top;
	int capacity;
	char *array;
};
typedef struct stack stack;
int isempty(stack *S)
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
	
	S->array[S->top] = value;
}
char pop(stack *S)
{
	if(S->top == -1)
	{
		printf("Cannot pop.Stack underflow\n");
		return 255;	
	}
	return S->array[S->top--];
}
int main()
{
	stack *S;
	int i;
	S=(stack *)malloc(sizeof(stack));
	S->capacity=10;
	S->array=(char *)malloc(sizeof(stack)*S->capacity);
	S->top=-1;
	char str1[10];
	char str2[10];
	printf("enter any string\n");
	scanf("%[^\n]s",str1);
	for(i=0;str1[i]!='\0';i++)
	{
		push(S,str1[i]);
	}
	i=0;
	while(isempty(S) != 1)
	{
		str2[i++] = pop(S);
		
	}
	
	
	for(i=0;str1[i]!='\0';i++)
	{
		if(str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			printf("string is not a palindrome\n");
			exit(1);
		}
	}
	printf("string is a palindrome\n");
	return 0;
}

	

