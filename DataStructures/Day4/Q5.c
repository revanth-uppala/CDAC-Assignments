/*Implement a Circular Queue using array implementation with
functions: enqueue, dequeue. Write a function display_queue to print
all elements*/
#include<stdio.h>
#include<stdlib.h>
struct QueueRecord
{
	int front,rear,capacity,size;
	int *arr;
};
typedef struct QueueRecord queue;
queue * Q;

int i;
isempty()
{
	return Q->size ==0;
}
isfull()
{
	return Q->size==Q->capacity;
}

void display()
{
	if(isempty())
	{
		printf("queue is empty\n");
		return;
	}
	i=Q->front;
	while(i!=Q->rear)
	{
		printf("%d>>",Q->arr[i]);
		i=succ(i);
	}
	printf("%d",Q->arr[i]);
	printf("\n");
}

int succ(int rear)
{
	rear++;
	if(rear == Q->capacity)
		rear=0;
	return rear;
}


void enqueue(int data)
{
	if(isfull())
	{
		printf("Queue is full\n");
		return;
	}
	Q->size++;
	Q->rear = succ(Q->rear);
	Q->arr[Q->rear] =data;
}

void dequeue()
{
	if(isempty())
	{
		printf("queue is empty\n");
		return;
	}
	Q->size--;
	Q->front=succ(Q->front);
}



	
	

int main()
{
	int data,ch;
	Q=(queue *)malloc(sizeof(queue));
	Q->capacity=10;
	Q->arr =(int *)malloc(sizeof(int)*Q->capacity);
	Q->size=0;
	Q->front=1;
	Q->rear=0;
	while(1)
	{
		printf("enter ur choice \n1.enqueue\n2.dequeue\n3.display queue\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter data to insert\n");
				scanf("%d",&data);
				enqueue(data);
				display();
				break;
			case 2:dequeue();
				display();
				break;
			case 3:display();
				break;
			case 4:exit(1);
			default:printf("invalid choice\n");
		}
	}
	return 0;
}
















	
