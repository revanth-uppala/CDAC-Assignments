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
node *insert_after(node *start,int data,int item)
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

node *insert_before(node *start,int data,int item)
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
	
int *search(node *start,int data)
{
	node *p;
	if(start == NULL)
	{
		return NULL;
	}
	p=start;
	while(p!=NULL)
	{
		if(p->info == data)
		{
		return p;
		}
		p=p->next;
	}
	return NULL;
}

void print_reverse(node *start)
{
	if(start ==NULL)
	{
		printf("list is empty\n");
		return;
	}
	
	node *temp =start;	
	int a=length(start);
	int arr[a],i;
	for(i=a-1;i>=0;i--)
	{
		arr[i]=temp->info;
		temp=temp->next;
	}
	printf("list in reverse order is\n");
	for(i=0;i<a;i++)
	{
		printf("%d>>",arr[i]);
	}
	printf("\n");
}
node *reverse(node *start)
{
	if(start == NULL)
	{
		printf("Cannot reverse.List is empty\n");
		return start;
	}
	node* prev,*ptr,*nextnode;
	prev = NULL;
	ptr = start;
	while(ptr != NULL)
	{
		nextnode = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = nextnode;
	}
	start = prev;
	return start;
}
node* swapnode(node *start,int data)
{
	if(start == NULL)
	{
		printf("Cannot swap.List is empty\n");
		return start;
	}	
	node *temp,*ptr,*prev;
	temp = start;
	prev = temp;
	while(temp->info != data)
	{
		prev = temp;		
		temp = temp->next;
		if(temp == NULL)
		{
			printf("Cannot swap.%d is not in list\n",data);
			return start;
		}
	}
	if(temp->next == NULL)
	{
		printf("%d is the last node.Cannot swap!\n",data);
		return start;
	}
	if(temp == start)
	{
		ptr = start->next;
		start->next = ptr->next;
		ptr->next = start;
		start = ptr;
		printf("After swapping:\n");		
		return start;
	}	
	ptr = temp->next;
	prev->next = ptr;
	temp->next = ptr->next;
	ptr->next = temp;
	printf("After swapping:\n");
	
	printf("\n");	
	return start;
} 
	
int main()
{ 
	int ch,data,item;
	int *position;
	node *start=NULL;
	while(1)
	{
		printf("1.add at begin\n2.addatend\n3.addafter\n4.addbefore\n5.delete\n6.display\n7.length\n8.search\n9.display reverse\n10.reverse the list\n11.Swap two nodes\n12.Quit");
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
			case 3: printf("enter data to add\n");
				scanf("%d",&data);
				printf("enter item after which to add\n");
				scanf("%d",&item);
				start = insert_after(start,data,item);
				display(start);
				printf("\n");
				break;
			case 4: printf("enter data to add\n");
				scanf("%d",&data);
				printf("enter item before which to add\n ");
				scanf("%d",&item);
				start = insert_before(start,data,item);
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
			case 8: printf("enter element u want to search\n");
				scanf("%d",&data);
				position = search(start,data);
				if(position!= NULL)
				{
				printf("%d is found at address %p\n",data,(node*)position);
				}
				else
				{
				printf("%d not found\n",data);
				}
				break;
			case 9:print_reverse(start);
				break;
			case 10:display(start); 
				printf("Before reversing, start points to %d\n",start->info);
				start = reverse(start);
				display(start);				
				printf("After reversing,start points to %d\n",start->info);				
				break;
			case 11:printf("Enter node to swap with next node\n");
				scanf("%d",&data);
				start = swapnode(start,data);
				display(start);
				break;
			case 12: exit(1);
			default : printf("invalid choice\n");
		}//switch close
	}//while close
	
	return 0;
}//main close
