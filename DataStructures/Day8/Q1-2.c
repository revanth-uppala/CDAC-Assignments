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
int max(int left,int right)
{
	return left>right ? left : right;
}
int height(BST *root)
{
	if(root == NULL)
	{
		return -1;
	}
	else
	{
		return max(height(root->left),height(root->right))+1;
	}
}
BST *insert_into_bst(BST *root,int val)
{
		
	if(root == NULL)
	{
		root = (BST*)malloc(sizeof(BST));
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else if(val > root->data)
	{
		root->right = insert_into_bst(root->right,val);
	}
	else if(val < root->data)
	{
		root->left = insert_into_bst(root->left,val);
	}
	return root;
}
BST *find_min_in_bst(BST *root)
{
	BST *temp = root;
	if(temp == NULL)
	{
		return NULL;
	}	
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}
BST *find_max_in_bst(BST *root)
{
	BST *temp = root;
	if(temp == NULL)
	{
		return NULL;
	}	
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

BST *search_parent(BST *root,int value)
{
	static unsigned short flag = 0;	
	if(root == NULL)
	{	
		if(flag == 0)
		{		
			printf("\nCannot Search.Tree is empty\n");
			flag++;
		}
		
		return root;
	}
	BST *temp,*lchild,*rchild;
	temp = root;
	lchild = temp->left;
	rchild = temp->right;
	if(value == temp->left->data || value == temp->right->data)
	{
		return temp;
	}
	if(value > (temp->data) )
	{
				
		temp = search_parent(rchild,value);
		
	}
	else if(value < (temp->data))
	{
				
		temp = search_parent(lchild,value);
	
	}
	else
	{
		return NULL;
	} 
}
		

BST *delete_from_bst(BST *root,int value)
{
	BST *lchild,*rchild,*p;	
	if(root == NULL)
	{
		printf("Cannot delete.Tree is empty\n");
		return root;
	}
	BST *temp = root;
	if(root->data == value && root->left == NULL && root->right == NULL)
	{
		root = NULL;
		free(temp);
		return root;
	}
	if(root->data == value && root->left != NULL && root->right == NULL)
	{
		root = root->left;
		free(temp);
		return root;
	}
	if(root->data == value && root->left == NULL && root->right != NULL)
	{
		root = root->right;
		free(temp);
		return root;
	}
	
	
	temp = search_parent(root,value); //temp = parent of node to delete
	if(temp == NULL)
	{
		printf("Cannot delete.%d not found in Tree\n",value);
		return root;
	}
	if(temp->left->data == value)
	{		
		p = temp->left;	//p = node to delete	
		if(p->left == NULL && p->right == NULL)
		{
			
			temp->left = NULL;
			free(p);
			return root;
		}
		else if(p->left != NULL && p->right == NULL)
		{
			temp->left = p->left;
			free(p);
			return root;
		}
		else if(p->left == NULL && p->right != NULL)
		{
			temp->left = p->right;
			free(p);
			return root;
		}
		else if(p->left != NULL && p->right != NULL)
		{
			lchild = p->left;
			rchild = p->right;
			rchild->left = lchild;
			temp->left = rchild;
			free(p);
			return root;
		}
	}
	else if(temp->right->data == value)
	{
		p = temp->right;//p = node to delete	
		if(p->left == NULL && p->right == NULL)
		{
			
			temp->left = NULL;
			free(p);
			return root;
		}
		else if(p->left != NULL && p->right == NULL)
		{
			temp->left = p->left;
			free(p);
			return root;
		}
		else if(p->left == NULL && p->right != NULL)
		{
			temp->left = p->right;
			free(p);
			return root;
		}
		else if(p->left != NULL && p->right != NULL)
		{
			lchild = p->left;
			rchild = p->right;
			rchild->left = lchild;
			temp->left = rchild;
			free(p);
			return root;
		}
	}	
}
void display(BST *root)
{
	
	BST *temp;	
	if(root == NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	push(root);		
		
	while(!IsEmpty())
	{	
		temp = pop();
		if(temp != NULL)
		{	
			printf("%d\t",temp->data);	
			push(temp->right);
			push(temp->left);
			
		}
		
	}
} 
void in_order_display(BST *root)
{
	if(root != NULL)
	{
		in_order_display(root->left);
		printf("%d\t",root->data);
		in_order_display(root->right);
	}
	
}
void post_order_display(BST *root)
{
	if(root != NULL)
	{
		post_order_display(root->left);
		post_order_display(root->right);
		printf("%d\t",root->data);
	}
}
int number_of_nodes(BST *root)
{
	static int nodes = 0,x;
	if(root != NULL)
	{
		number_of_nodes(root->left);
		
		number_of_nodes(root->right);
	}
	return nodes++;
}

	
	
                                                                                                                                                                                                        
	
	
	
		

BST *search(BST *root,int value)
{
	static unsigned short flag = 0;	
	if(root == NULL)
	{	
		if(flag == 0)
		{		
			printf("\nCannot Search.Tree is empty\n");
			flag++;
		}
		
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
}
BST *insert_non_recursive(BST *root,int val)
{
	if(root == NULL)
	{
		root = (BST*)malloc(sizeof(BST));
		root->data = val;
		root->left = NULL;
		root->right = NULL;
		return root;	
	}
	BST *temp ;
	BST *prev;
	temp = root;
	while(temp != NULL)
	{
		if(val > temp->data)
		{
			prev = temp;				
			temp = temp->right;
		}
		else if(val < temp->data)
		{
			prev = temp;				
			temp = temp->left;
		}
		else
		{
			printf("Duplicate element.Cannot Insert\n");
			return root;
		}
	}
	BST *new = (BST*)malloc(sizeof(BST));
	new->data = val;
	new->left = NULL;
	new->right = NULL;	
	if(val < prev->data)
	{
		prev->left = new;
	}
	else if(val > prev->data)
	{
		prev->right = new;
	}
	return root;
}
	
		
	
	

			
int main()
{
	BST *root = NULL;
	int val;
	BST *temp;
	unsigned int ch;
	while(1)
	{
		printf("\nEnter choice :\n1.insert_into_bst\n2.deletion_from_bst\n3.find_in_bst\n4.find_min_in_bst\n5.find_max_in_bst\n6.Pre-Order Display\n7.In-order Display\n8.Post-order Display\n9.Number of nodes\n10.height\n11.Insert(non-recursive\n12.Exit\n");
	scanf("%u",&ch);
		switch(ch)
		{
			case 1: printf("Enter data to insert\n");
				scanf("%d",&val);			
				root = insert_into_bst(root,val);
				display(root);
				break;
			case 2: printf("Enter node to delete\n");
				scanf("%d",&val);
				root = delete_from_bst(root,val);
				display(root);
				break;
			
			case 3: printf("Enter data to search\n");
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
				break;
			case 4: temp = find_min_in_bst(root);
				if(temp == NULL)			
				{			
					printf("Tree empty\n");
				}
				else
				{
					printf("%d is minimum in tree\n",temp->data);
				}
				break;
			case 5: temp = find_max_in_bst(root);
				if(temp == NULL)			
				{			
					printf("Tree empty\n");
				}
				else
				{
					printf("%d is maximum in tree\n",temp->data);
				}
				break;
			case 6: printf("Pre Order display\n"); 
				display(root);
				break;
			case 7: printf("In Order display:\n");	
				in_order_display(root);
				break;
			case 8 :printf("Post Order display:\n"); 
				post_order_display(root);
				break;			
			case 9: val = number_of_nodes(root);
				printf("Number of nodes = %d\n",val);
				break;
			case 10:val=height(root);
				if(val == -1)
				{
					printf("tree is empty\n");
				}
				else
				{
				printf("height of tree is %d\n",val);		
				}				
				break;	
			case 11:printf("Enter value to insert\n");
				scanf("%d",&val);
				root = insert_non_recursive(root,val);
				display(root);				
				break;			
			case 12: exit(1);
			default : printf("Invalid choice\n");
		}//switch closed
	}//while closed
	return 0;
}
