#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
extern node *start = NULL;
extern node *last = NULL;
void insert_begin(int value)
{
	
	node *new;
	new = (node *)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Cannot insert\n");
		return;
	}
	new->data = value;	
	if(start == NULL)
	{
		start = new;
		start->next = NULL;
		start->prev = NULL;
		last = new;
		return;
	}
	new->next = start;
	start->prev = new;
	start = new;
	start->prev = NULL;
	
}
