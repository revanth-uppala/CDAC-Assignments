#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;


node *insert_end(node *last,int data)
{
	node *temp,*p;
	temp=(node*)malloc(sizeof(node));
	temp->info = data;
	if(last == NULL)
	{
	temp->next=last;
	last=temp;
	return last;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
		last=temp;
		return last;
	}
}
