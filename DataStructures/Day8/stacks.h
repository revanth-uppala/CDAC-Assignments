/*Write a program to implement Stack using Linked stack .*/

struct Binary_Search_Tree
{
	int data;	
	struct Binary_Search_Tree *left;
	struct Binary_Search_Tree *right;
};
typedef struct Binary_Search_Tree BST;

typedef struct node
{
	int size;
	BST *root;
	struct node *next;
}node;
BST* pop_data = NULL;
node *top = NULL;
int IsEmpty()
{
	if(top == NULL)
	{
		return 1;
	}	
	else
	{
		return 0;
	}
}

void push(BST *data)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp-> root = data;
	temp->next = top;
	top=temp;
	top->size++;
}

BST *pop()
{
	node *temp;
	if(top == NULL)
	{
		
		return pop_data;
	}
	temp = top;	
	pop_data = top->root;
	top->size--;
		
	top = top->next;
	free(temp);	
	return pop_data;
}

			

			




