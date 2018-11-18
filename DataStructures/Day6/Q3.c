/*Write a function “selection_sort” to implement Selection Sort. Pass
array “arr” and size “n” as arguments from main.*/
#include<stdio.h>
#define MAX 20
void selection_sort(int arr[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j] < arr[min])
			{
				min=j;
			}
		}
		if(i!=min)
		{
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		}		
	}
}
		
int main()
{
	int arr[MAX];
	int n,i;
	printf("enter no of elements\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	printf("after sorting\nelements are\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}	

	
