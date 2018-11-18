#include<stdio.h>
#include<stdlib.h>
#include "header.h"
/*typedef struct node
{
	int info;
	struct node *next;
}node;*/

/*void display(node* last)
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
}//end of insert_end*/


int main()
{ 
	int ch,data;
	node *last=NULL;
	while(1)
	{
		printf("1.add at begin\n2.addatend\n3.display\n4.Quit");
		printf("\nEnter ur choice\n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: printf("enter data to add\n");
				scanf("%d",&data);
				last= insert_beg(last,data);
				display(last);
				printf("\n");
				break;

			case 2: printf("enter data to add\n");
				scanf("%d",&data);
				last = insert_end(last,data);
				display(last);
				printf("\n");
				break;
			case 3:display(last);
				break;
			case 4: exit(1);
			default: printf("invalid choice\n");
		}//end of switch
	
	}//end of while
	return 0;
}//end of main




