#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
extern node *start;
extern node *last;
/*node *start = NULL;
node *last = NULL;*/
void delete_end()
{
	node *temp;
	if(last == NULL)
	{
		printf("List is empty.Underflow\n");
		return;
	}
	if(start == last)
	{
		temp = start;
		start = NULL;
		last = NULL;
		free(temp);
		return;
	}		
	temp = last;
	last = last->prev;
	last->next = NULL;	
	free(temp);
}
