/*Write a program to search for an element in a given list of elements. Use break statement*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int element,i,l;
	printf("Enter list range\n");
	scanf("%d",&l);
	int a[l];	
	printf("Enter list elements\n");
	for(i = 0; i < l ; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element\n");
	scanf("%d",&element);	
	for(i = 0;i<l;i++)
	{
		if(a[i] == element)
		{
			printf("%d was found in position %d",element,i);
			exit(1);
		}
	}
	printf("%d not found in list\n",element);
		
	return 0;
}
	
