#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;

void display(node* start)
{
 	node *p;
	if(start == NULL)
	{
		printf("list is empty\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%d>>>",p->info);
		p=p->next;
	}
	printf("\n");
}

node *insert_beg(node *start,int data)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info =data;
	temp->next=start;
	start=temp;
	return start;
}


node *self_adjusting_find(node *start,int data)
{
	node *temp,*p,*q;
	p=start;
	char flag='N';
	while(p!=NULL)
	{
		if(p->info == data)
		{
			flag ='Y';
			break;
		}
		p=p->next;
	}
	if(flag == 'N')
	{
		printf("data not found in list\n");
		return start;
	}
	temp=(node *)malloc(sizeof(node));
	temp->info=data;
	temp->next=start;
	start=temp;
	p=start;
	while(p->next != NULL)
	{
		if(p->next->info ==data)
		{
			q=p->next;
			p->next=q->next;
			free(q);
			return start;
		}
	p=p->next;
	}
}//end of selfadjusting find
	

int main()
{ 
	int ch,data;
	node *start=NULL;
	while(1)
	{
		printf("1.add at begin\n2.self adjusting find\n3.display\n4.Quit\n");
		printf("\nEnter ur choice\n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: printf("enter data to add\n");
				scanf("%d",&data);
				start=insert_beg(start,data);
				display(start);
				break;
			case 2:printf("enter data to self adjuist\n");
			       scanf("%d",&data);
			       start=self_adjusting_find(start,data);
			       display(start);
			       break;
			case 3:display(start);
			       break;
		        case 4:exit(1);
				
		        default: printf("invlaid choice\n");
		}//end of switch
	}//end of while
	return 0;
}














