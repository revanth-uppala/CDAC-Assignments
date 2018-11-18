#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
void display(node* head)
{
	node *temp;
	if(head == NULL)
	{
		printf("Linked List is empty\n");
		return;
	}	
	temp = head;
	while(temp->next != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d->",temp->data);
	printf("\n\n");
}
node* insertbegin(node* head,int val)
{
	node *new;
	new = (node*)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Cannot insert.Overflow\n");
		return head;
	}	
	new->data = val;
	if(head == NULL)
	{
		head = new;
		head->next = NULL;
		return head;	
	}
	new->next = head;
	head = new;
	return head;
}
node* insertend(node* head,int val)
{
	node *new,*temp;
	new = (node*)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Cannot insert.Overflow\n");
		return head;
	}	
	new->data = val;
	if(head == NULL)
	{
		head = new;
		head->next = NULL;
		return head;	
	}
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->next = NULL;
	return head;
}
node* insertafter(node* head,int val,int pos)
{
	node *new,*temp;
	new = (node*)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Cannot insert.Overflow\n");
		return head;
	}	
	new->data = val;
	temp = head;
	while(temp->data != pos)
	{
		temp = temp->next;
		if(temp == NULL)
		{
			printf("%d node not present in Linked List\n",pos);
			return head;
		}
	}
	if(temp->next == NULL)
	{
		return insertend(head,val);
	}	
	new->next = temp->next;
	temp->next = new;
	return head;
}
node* deletebegin(node* head)
{
	node *temp;	
	if(head == NULL)
	{
		printf("List is empty.Underflow\n");
		return head;
	}	
	
	temp = head;
	head = temp->next;
	free(temp);
	return head;
}
node* deleteend(node* head)
{
	node *temp,*previous;
	if(head == NULL)
	{
		printf("List is empty.Underflow\n");
		return head;
	}
	temp = head;
	previous = head;
	while(temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	free(temp);
	
	return head;
	
}	
node* deleteafter(node* head,int pos)
{
	node *temp,*previous;
	if(head == NULL)
	{
		printf("List is empty.Underflow\n");
		return head;
	}	
	temp = head;
	previous = temp;	
	while(temp->data != pos)
	{
		previous = temp;		
		temp = temp->next;
		if(temp == NULL)
		{
			printf("%d not found in list\n",pos);
			return head;
		}
	}
	if(temp->next == NULL)
	{	
		return deleteend(head);
	}
	previous->next = temp->next;
	free(temp);
	return head;
	
}




int main()
{
	node *head;
	head = 	NULL;
	int ch,data,pos;
	while(1)
	{	
		printf("\nEnter choice:\n1.Insert at beginning\n2.Insert at end\n3.Insert after node\n4.Delete at beginning\n");
		printf("5.Delete at end\n6.Delete node\n7.Display\n8.Quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter value to insert\n");
				scanf("%d",&data);
				head = insertbegin(head,data);
				printf("After inserting %d :\n",data);
				display(head);
				break;
			case 2:
				printf("Enter value to insert\n");
				scanf("%d",&data);
				head = insertend(head,data);
				printf("After inserting %d :\n",data);
				display(head);
				break;
			case 3:
				printf("Enter value to insert\n");
				scanf("%d",&data);
				display(head);
				printf("Select node after which to enter %d :",data);				
				scanf("%d",&pos);				
				head = insertafter(head,data,pos);
				printf("After inserting %d :\n",data);
				display(head);
				break;
			case 4:
				head = deletebegin(head);
				printf("After deleting head node\n");
				display(head);
				break;
			case 5:
				head = deleteend(head);
				printf("After deleting last node:\n");
				display(head);
				break;
			case 6:
				printf("Enter node to be deleted\n");
				scanf("%d",&pos);
				head = deleteafter(head,pos);
				display(head);				
				break;
			case 7:display(head);
				break;
			case 8: exit(1);
			default: printf("Invalid input!\n");
		} //switch closed
	}//while closed
	return 0;
}
	

