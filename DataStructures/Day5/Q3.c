/*Implement Searching an element from the list using linear search.*/
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



node *insert_end(node *start,int data)
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


			


	
int search(node *start,int data)
{
	node* p;
	int pos = 0;
	if(start == NULL)
	{
		return -998;
	}
	p=start;
	while(p!=NULL)
	{
				
		if(p->info == data)
		{
		return pos;
		}
		p=p->next;
		pos++;
	}
	return -999;
}



int main()
{ 
	int ch,data,item;
	int position;
	node *start=NULL;
	while(1)
	{
		printf("1.add at begin\n2.addatend\n3.delete\n4.display\n5.search\n6.Quit");
		printf("\nEnter ur choice\n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: printf("enter data to add\n");
				scanf("%d",&data);
				start = insert_beg(start,data);
				display(start);
				printf("\n");
				break;

			case 2: printf("enter data to add\n");
				scanf("%d",&data);
				start = insert_end(start,data);
				display(start);
				printf("\n");
				break;
			
			case 3: display(start);
				printf("enter data to delete\n");
				scanf("%d",&data);
				start = delete(start,data);
				display(start);
				printf("\n");
				break;
			case 4: display(start);
				break;
		
			case 5: printf("enter element u want to search\n");
				scanf("%d",&data);
				position = search(start,data);
				if(position!= -999 && position != -998)
				{
					printf("%d is found at position %d \n",data,position);
				}
				else if(position == -999)
				{
					printf("%d not found\n",data);
				}
				else
				{
					printf("List is empty.Cannot search\n");
				}
				break;
			
			case 6: exit(1);
			default : printf("invalid choice\n");
		}//switch close
	}//while close
	
	return 0;
}//main close
