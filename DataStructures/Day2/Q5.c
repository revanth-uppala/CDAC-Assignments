/*Write a program to implement Singly Linked lists of integers.
Write function insert_end() to insert an element at end of linked
list. Take Linked List pointer and integer as two arguments.
Write function insert_beg() to insert at beginning of linked list.
Take Linked List pointer and integer as two arguments.
Write function delete_beg() & delete_end() to delete element from
linked list. Take Linked List pointer only as single argument.
Write function search() to search as element in Linked list and
return node address. Return NULL for failed search.
Write function insert_after() to insert an element after above
search() function. Insert element at end for failed search().
Write function display() to print the elements of linked list. Take
Linked List pointer only as single argument.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}node;
typedef struct LinkedList
{
	 node *start;	
	
}LL;
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
	temp->next= NULL;
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


			

			





	
int main()
{ 
	int ch = 0,data,item;
	int *position,count = 0;
	LL LL1,LL2,LL3;	
	LL1.start = NULL;
	LL2.start = NULL;
	LL3.start = NULL;
	printf("Enter elements of first Linked List\n");
	do
	{	
		printf("enter data to add\n");
		scanf("%d",&data);
		if(count == 0)	
		{	
			LL1.start = insert_beg(LL1.start,data);
			count++;
		}
		else
		{
			LL1.start = insert_end(LL1.start,data);
		}
		printf("\nPress 1 to enter another node\n");
		scanf("%d",&ch);	
	}
	while(ch == 1);
	count = 0;
	
	printf("\nEnter elements of second Linked List\n");
	do
	{	
		printf("enter data to add\n");
		scanf("%d",&data);
		if(count == 0)	
		{	
			LL2.start = insert_beg(LL2.start,data);
			count++;
		}
		else
		{
			LL2.start = insert_end(LL2.start,data);
		}
	
		printf("\nPress 1 to enter another node\n");
		scanf("%d",&ch);	
	}
		
	while(ch == 1);
	count = 0;
	printf("First Linked List is:\n");
	display(LL1.start);
	printf("Second Linked List is:\n");
	display(LL2.start);
	node* temp1,*temp2;
	temp1 = LL1.start;
	temp2 = LL2.start;
	while(temp1 != NULL)
	{
		temp2 = LL2.start;		
		while(temp2 != NULL)
		{
			if(temp1->info == temp2->info)
			{
				if(count == 0)				
				{
					LL3.start = insert_beg(LL3.start,temp1->info);
					count++;				
				}
				else
				{
					LL3.start = insert_end(LL3.start,temp1->info);
				}	
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	printf("Intersection of Linked List 1 and Linked List 2 is:\n");
	display(LL3.start);
	return 0;
}//main close
