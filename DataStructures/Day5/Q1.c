/*Write a program to implement Stack using Linked stack .*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}node;
int pop_data;
void display(node* top)
{
 	node *p;
	if(top == NULL)
	{
		printf("stack is empty\n");
		return;
	}
	p=top;
	while(p!=NULL)
	{
		printf("|%d|\n",p->info);
		p=p->next;
	}
	printf("\n");
}

node *push(node *top,int data)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info =data;
	temp->next=top;
	top=temp;
	return top;

}






node *pop(node* top)
{
	node *temp;
	if(top == NULL)
	{
		printf("stack is empty\n");
		return top;
	}
	temp = top;	
	pop_data = top->info;
	printf("\nPopped data = %d\n",pop_data);	
	top = top->next;
	free(temp);	
	return top;
}

			

			



	
int main()
{ 
	int ch,data,item;
	int *position;
	node *top=NULL;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("\nEnter ur choice\n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: printf("enter data to add\n");
				scanf("%d",&data);
				top = push(top,data);
				display(top);
				printf("\n");
				break;

			
			case 2: display(top);
				top = pop(top);
				
				
				break;
			case 3: display(top);
				break;
			case 4: exit(1);
			
			default : printf("invalid choice\n");
		}//switch close
	}//while close
	
	return 0;
}//main close
