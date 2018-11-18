/*Implement a doubly linked list program with functions:
insert_at_beg, insert_at_end, delete_at_beg, delete_at_end & search.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
node *start = NULL;
node *last = NULL;
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
void insert_end(int value)
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
	last->next = new;
	new->prev = last;
	new->next = NULL;
	last = new;	
}
void delete_begin()
{
	node *temp;
	if(start == NULL)
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
	temp = start;
	start = start->next;
	start->prev = NULL;
	free(temp); 
}
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
int search(int value)
{
	int pos = 0;
	node *temp;
	temp = start;
	while(temp != NULL)
	{
		if(temp->data == value)
		{
			return pos;
		}
		pos++;
		temp = temp->next;
	}
	return -999;
}
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
int main()
{
	
	int ch,data,pos;
	while(1)
	{	
		printf("Enter choice:\n1.Insert at beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Search\n6.Display\n7.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the data\n");
				scanf("%d",&data);
				insert_begin(data);
				printf("After inserting %d:\n",data);
				display();
				break;
			case 2: printf("Enter the data\n");
				scanf("%d",&data);
				insert_end(data);
				printf("After inserting %d:\n",data);
				display();
				break;	
			case 3: delete_begin();
				printf("After deleting first node:\n");
				display();
				break;
			case 4: delete_end();
				printf("After deleting last node:\n");
				display();
				break;
			case 5: printf("Enter the element to search\n");
				scanf("%d",&data);
				pos = search(data);
				if(pos == -999)
				{
					printf("%d not found in list\n",data);
				}
				else
				{
					printf("%d found at position %d\n",data,pos+1);
				}
				break;
			case 6: display();
				break;
			case 7: exit(1);
		}//switch closed
	}//while closed
	return 0;
}

