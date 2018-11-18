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

node *addatbegin(node *start,int data)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info =data;
	temp->next=start;
	start=temp;
	return start;

}



node *addatend(node *start,int data)
{
	node *temp,*p;
	if(start == NULL)
	{
		printf("list is empty\n");
		return start;
	}
	temp=(node*)malloc(sizeof(node));
	temp->info = data;
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
	return start;
}
node *addafter(node *start,int data,int item)
{
	node*temp,*p;
	if(start == NULL)
	{
		printf("list is empty\n");
		return start;
	}
	temp=(node*)malloc(sizeof(node));
	temp->info=data;
	if(start->info == item)
	{
		temp->next=start->next;
		start->next=temp;
		return start;
	}
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp->next=p->next;
			p->next=temp;
			return start;
		}
		p=p->next;
	}
		printf("%d not found in list\n",item);
	return start;
}

node *delete(node* start,int data)
{
	node*p,*temp;
	if(start == NULL)
	{
		printf("list is empty\n");
		return start;
	}
	if(start->info==data)
	{
		start=start->next;
		return start;
	}
	p=start;
	while(p->next!=NULL)
	{
		if(p->next->info ==data)
		{
			temp=p->next;
			p->next=temp->next;
			free(temp);
			return start;
		}
	p=p->next;
	}
		printf("%d not found\n",data);
		return start;
}

node *addbefore(node *start,int data,int item)
{
	node*p,*temp;
	if(start == NULL)
	{
		printf("list is empty\n");
		return start;
	}
	temp=(node*)malloc(sizeof(node));
	temp->info=data;
	if(start->info==item)
	{
		temp->next=start;
		start=temp;
		return start;
	}
	p=start;
	while(p!=NULL)
	{
		if(p->next->info==item)		
		{
			temp->next=p->next;
			p->next=temp;
			return start;
		}
		p=p->next;
	}
	printf("%d not found in list\n",item);
	return start;
}
			

			
int length(node *start)
{
	int cnt=0;
	node*p;
	p=start;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

int main()
{ 
	int ch,data,item;
	node *start=NULL;
	while(1)
	{
		printf("1.add at begin\n2.addatend\n3.addafter\n4.addbefore\n5.delete\n6.display\n7.length\n8.quit\n");
		printf("enter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter data to add\n");
				scanf("%d",&data);
				start = addatbegin(start,data);
				display(start);
				printf("\n");
				break;

			case 2: printf("enter data to add\n");
				scanf("%d",&data);
				start = addatend(start,data);
				display(start);
				printf("\n");
				break;
			case 3: printf("enter data to add\n");
				scanf("%d",&data);
				printf("enter item after which to add\n");
				scanf("%d",&item);
				start = addafter(start,data,item);
				display(start);
				printf("\n");
				break;
			case 4: printf("enter data to add\n");
				scanf("%d",&data);
				printf("enter item before which to add\n ");
				scanf("%d",&item);
				start = addbefore(start,data,item);
				display(start);
				printf("\n");
				break;
			case 5: display(start);
				printf("enter data to delete\n");
				scanf("%d",&data);
				start = delete(start,data);
				display(start);
				printf("\n");
				break;
			case 6: display(start);
				break;
			case 7: printf("length of list is %d\n",length(start));
				break;
			case 8:exit(1);
			default : printf("invalid choice\n");
		}//switch close
	}//while close
	
	return 0;
}//main close
