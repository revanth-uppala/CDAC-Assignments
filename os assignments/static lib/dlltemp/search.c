#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
extern node *start;
/*node *start = NULL;
node *last = NULL;*/
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
