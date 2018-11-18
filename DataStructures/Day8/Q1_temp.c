/*Create Binary Search Tree(BST) with the following functions
1. insert_into_bst
2. deletion_from_bst
3. fnd_in_bst
4. fnd_min_in_bst
5. fnd_max_in_bst*/
#include<stdio.h>
#include<stdlib.h>
#include "stacks.h"
/*struct Binary_Search_Tree
{
	int data;	
	struct Binary_Search_Tree *left;
	struct Binary_Search_Tree *right;
};
typedef struct Binary_Search_Tree BST;*/
node* temp;
BST *insert_into_bst(BST *root,int val)
{
	BST *temp,*new;
	new = (BST*)malloc(sizeof(BST));	
	if(new == NULL)
	{
		printf("Cannot insert!\n");
		return root;
	}	
	new->data = val;
	new->left = NULL;
	new->right = NULL;	
	if(root == NULL)
	{
		root = new;
		return root;	
	}
	temp = root;
	while(temp != NULL)
	{
		if(val < temp->data)
		{
			if(temp->left != NULL)
			{			
				temp = temp->left;
			}
			else
			{
				temp->left = new;
				return root;
			}
		}
		else if(val > temp->data)
		{
			if(temp->right != NULL)
			{			
				temp = temp->right;
			}
			else
			{
				temp->right = new;	
				return root;			
			}
		}
	}
}
/*BST *deletion_from_bst(BST *root,int value)
{
	if(root == NULL)
	{
		printf("Cannot delete.Tree is empty\n");
	}
	BST *temp = root;
	if(temp->data == value)
	{
		root = NULL;
		free(temp);
		return root;
	}
	temp = search(root,value);
	if(temp == NULL)
	{
		printf("Cannot delete.%d not found in Tree\n",value);
		return root;
	}
	else
	{
		//	
	}	
}*/
void display(BST *root)
{
	BST *temp,*lchild,*rchild;
		
	temp = root;
	if(temp == NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	push(temp);		
	while(!IsEmpty())
	{	
		temp = pop();
		if(temp != NULL)
		{	
			printf("%d\t",temp->data);	
			push(rchild);
			push(lchild);
			lchild = temp->left;
			rchild = temp->right;
		}
		
	}
} 
	
                                                                                                                                                                                                        
	
	
	
		

/*BST *search(BST *root,int value)
{
	if(root == NULL)
	{
		printf("Cannot Search.Tree is empty\n");
		return root;
	}
	BST *temp,*lchild,*rchild;
	temp = root;
	lchild = temp->left;
	rchild = temp->right;
	if(value == temp->data)
	{
		return temp;
	}
	if(value > (temp->data) )
	{
		temp = search(rchild,value);
	}
	else if(value < (temp->data))
	{
		temp = search(lchild,value);
	}
	else
	{
		return NULL;
	} 
}*/
		
	
	

			
int main()
{
	BST *root = NULL;
	BST *temp;
	unsigned int ch,val;
	while(1)
	{
		printf("Enter choice :\n1. insert_into_bst\n2.deletion_from_bst\n3.find_in_bst\n4.find_min_in_bst\n5.find_max_in_bst\n6.Display\n7.Exit\n");
	scanf("%u",&ch);
		switch(ch)
		{
			case 1: printf("Enter data to insert\n");
				scanf("%d",&val);			
				root = insert_into_bst(root,val);
				display(root);
				break;
			case 2: /*printf("Enter node to delete\n");
				root = delete_from_bst(root,val);
				display(root);
				break;*/
			
			case 3: /*printf("Enter data to search\n");
				scanf("%d",&val);			
				temp = search(root,val);
				if(temp == NULL)
				{
					printf("%d not found in Tree\n",val);
				}
				else
				{
					printf("%d found in Tree\n",temp->data);
				}				
				display(root);
				break;*/
			case 4: /*val = find_min_in_bst(root);
				if(val != -999)			
				{			
					printf("Tree empty\n");
				}
				else
				{
					printf("%d is minimum in tree\n");
				}
				break;*/
			case 5: /*val = find_max_in_bst(root);
				if(val != -999)			
				{			
					printf("Tree empty\n");
				}
				else
				{
					printf("%d is maximum in tree\n");
				}
				break;*/
			case 6: display(root);
				break;			
			case 7: exit(1);
			default : printf("Invalid choice\n");
		}//switch closed
	}//while closed
	return 0;
}
