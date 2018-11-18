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
void display()
{
	node *temp;
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}	
	temp = start;
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
