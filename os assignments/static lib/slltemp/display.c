#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;

void display(node* last)
{
 	node *p;
	
	if(last == NULL)
	{
		printf("list is empty\n");
		return;
	}
	p=last->next;
	
	do
	{
		printf("%d>>>",p->info);
		p=p->next;
	}while(p!=last->next);
	printf("\n");
}
