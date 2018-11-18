/*Implement Hashing technique using Open addressing and Separate
Chaining*/
/*Open Addressing*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 7
int IsFull(int arr[])
{
	int i;
	for(i = 0 ; i < MAX ; i ++)
	{
		if(arr[i] == -1)
		{
			return 0;
		}
	}
	return 1;
}
int EmptyIndex(int arr[])
{
	int i;
	for(i = 0 ; i < MAX ; i ++)
	{
		if(arr[i] == -1)
		{
			return i;
		}
	}
	printf("Table is full\n");
	exit(1);
}
		
int hash(int temp,int arr[])
{
	int i = temp%MAX;	
	if(arr[i] == -1)
	{
		return i;
	}
	else
	{
		while(arr[i] != -1 && i < MAX)
		{
			i++;
		}
		if(i == MAX)
		{
			i = EmptyIndex(arr);
		}		
		return i;
	}
}
void Display(int arr[])
{
	int i;
	printf("The Hash table is\n");
	for(i = 0 ; i < MAX; i ++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int Search(int arr[],int key)
{
	int i = key % MAX,j;	
	if(i == key)
	{
		return i;
	}
	else
	{
		for(j = i ; j < MAX ; j++)
		{
			if(arr[j] == key)
			{
				return j;
			}
		}
		for(j = 0 ; j < i ; j ++)
		{
			if(arr[j] == key)
			{
				return j;
			}
		}
		return -1;
	}
}
		
	
	
			
int main()
{
	int i,temp,key,arr[MAX];
	for(i = 0 ; i < MAX ; i++)
	{
		arr[i] = -1;
	}
	printf("enter elements of array\n");
	for(i=0;i<MAX;i++)
	{
		if(!IsFull(arr))
		{		
			scanf("%d",&temp);
			arr[hash(temp,arr)]=temp;
		}
		else
		{
			printf("Cannot insert.Table Full\n");			
			break;
		}
	}
	Display(arr);
	char ch;
	do
	{
		printf("Enter element to search\n");
		scanf("%d",&key);
		if(Search(arr,key) != -1)
		{
			printf("%d found in %d location\n",key,Search(arr,key));
		}
		else
		{
			printf("%d not found in table\n",key);
		}
		printf("Press Y to search another element\n");
		scanf(" %c",&ch);
	}
	while(ch == 'Y');
}
	
	
