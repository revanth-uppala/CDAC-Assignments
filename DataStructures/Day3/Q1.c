#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co;
	struct node *next;
};
typedef struct node node;
struct Polynomial
{
		node *start;
		int degree;
};
typedef struct Polynomial poly;
void display(node* start)
{
	int i = 0; 	
	node *p;
	p = start;
	while(p != NULL)
	{
		if(p->next != NULL)
		{		
			printf("%dx^%d + ",p->co,i++);
		}
		else
		{
			printf("%dx^%d",p->co,i++);
		}			
		p=p->next;
	}
	printf("\n");
}





node *insert_end(node *start,int data)
{
	node *temp,*p;
	temp=(node*)malloc(sizeof(node));
	temp->co = data;	
	if(start == NULL)
	{
		start = temp;
		start->next = NULL;	
		return start;
	}
	
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
	return start;
}
poly add_poly(poly P1,poly P2)
{
	poly P3;
	P3.start = NULL;	
	node *smaller,*bigger;
	smaller = (P1.degree > P2.degree ? P2.start : P1.start);
	bigger = (P1.degree > P2.degree ? P1.start : P2.start);	
	while( bigger != NULL)
	{
		if(smaller == NULL)
		{
			
				P3.start = insert_end(P3.start,bigger->co);	
			
		}		
		else
		{		
			P3.start = insert_end(P3.start,bigger->co + smaller->co);
		}	
		
		
		
		bigger = bigger->next;
		if(smaller != NULL)
		{		
			smaller = smaller->next;
		}
	}
	return P3;
}
int main()
{ 
	int ch = 0,data,i;
	int *position;
	poly P1,P2,P3;	
	P1.start = NULL;
	P2.start = NULL;
	P3.start = NULL;
	printf("Enter degree of Polynomial 1\n");
	scanf("%d",&P1.degree);
	for(i = 0 ; i <= P1.degree ; i ++)
	{
		printf("enter coefficient of x^%d \n",i);
		scanf("%d",&data);
		P1.start = insert_end(P1.start,data);
	}
	
	printf("Enter degree of Polynomial 2\n");
	scanf("%d",&P2.degree);
	for(i = 0 ; i <= P2.degree ; i ++)
	{
		printf("enter coefficient of x^%d \n",i);
		scanf("%d",&data);
		P2.start = insert_end(P2.start,data);
	}
	//printf("Polynomial 1 is:\n");
	printf(" \t");	
	display(P1.start);
	//printf("Polynomial 2 is:\n");
	printf("+\t");
	display(P2.start);
	printf("\t");	
	for(i = 0 ; i < (P1.degree > P2.degree ? P1.degree : P2.degree)*10 ; i ++)
	{
		printf("____");
	}
	printf("\n");	
	P3 = add_poly(P1,P2);
	printf(" \t");
	display(P3.start);
	printf("\n");
return 0;
}
	
