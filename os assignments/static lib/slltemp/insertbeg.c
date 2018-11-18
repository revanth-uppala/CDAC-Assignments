#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;


node *insert_beg(node *last,int data)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info =data;
	if(last == NULL)
	{
	last=temp;
	last->next=last;
	return last;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
		return last;
	}

}


