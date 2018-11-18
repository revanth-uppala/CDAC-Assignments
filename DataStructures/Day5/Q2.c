/*Write a program to implement Queue using Linked List.*/
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
		printf("Queue is empty\n");
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
int front(node* start)
{
	if(start == NULL)
	{
		return -999;
	}
	return start->info;
}




node *Enqueue(node *start,int data)
{
	node *temp,*p;
		
	if(start == NULL)
	{
		temp=(node*)malloc(sizeof(node));
		temp->info = data;
		start = temp;
		temp->next = NULL;
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


node *Dequeue(node* start)
{
	node*temp;
	if(start == NULL)
	{
		printf("Queue is empty\n");
		return start;
	}
	temp = start;
	start = start->next;
	free(temp);
	return start;
	
}

		



	
int main()
{ 
	int data,ch;
	
	node *start=NULL;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Front\n4.Display\n5.Exit\n");
		printf("\nEnter ur choice\n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: printf("enter data to add\n");
				scanf("%d",&data);
				start = Enqueue(start,data);
				display(start);
				printf("\n");
				break;

			case 2: 
				start = Dequeue(start);
				display(start);
				printf("\n");
				break;
			case 3: data = front(start);
				if(data != -999)
				{
					printf("Front = %d\n",data);
				}
				else
				{
					printf("Queue is empty\n");
				}
				printf("\n");
				break;
			case 4: display(start);
				break;
			case 5: exit(1);
			
			default : printf("invalid choice\n");
		}//switch close
	}//while close
	
	return 0;
}//main close
