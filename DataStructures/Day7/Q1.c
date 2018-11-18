/*Write a function “quick_sort” to implement Selection Sort. Pass
array “arr” and size “n” as arguments from main.*/
#include<stdio.h>
#define MAX1 20
void quick_sort(int arr[],int n);
void qsort(int arr[],int left,int right);
void swap(int *p,int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void quick_sort(int arr[],int n)
{
	int left = 0;
	int right = n-1;
	qsort(arr,left,right);
}
void qsort(int arr[],int left,int right)
{
	if(left < right)
	{
		int i,j,pivot,pivot_index;
		i = left;
		j = right - 1;
		pivot = arr[right];
		pivot_index = right;
		while(1)
		{		
			while(arr[i] < pivot && i <= right - 1)
			{	
				i++;
			}
			while(arr[j] > pivot && j >= left)
			{
				j--;
			}
			if(i < j)
			{
				swap(&arr[i],&arr[j]);
			}
			else
				break;
		}//infinite loop ends
		swap(&arr[i],&arr[pivot_index]);
		qsort(arr,left,i-1);
		qsort(arr,i+1,right);
	}
}



		
int main()
{
	int arr[MAX1];
	int n,i;
	printf("enter no of elements\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i = 0 ; i < n ; i ++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,n);
	printf("after sorting\nelements are\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}	

	
