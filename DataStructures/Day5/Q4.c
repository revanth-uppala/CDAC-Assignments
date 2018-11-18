/*Implement Searching an element from the list using binary search*/
#include<stdio.h>
#define MAX 20
int binary_search(int a[],int left,int right,int element)
{
	int mid = (left + right)/2;
	if(left > right)
	{
		return -999;
	}	
	if(element == a[mid])
	{
		return mid;
	}
	else if(element < a[mid])
	{
		return binary_search(a,left,mid - 1,element);
	}
	else if(element > a[mid])
	{
		return binary_search(a,mid + 1,right,element);
	}
	
	
}	
int main()
{
	int a[MAX],n,i,element,result,left,right;	
	printf("Enter array size\n");
	scanf("%d",&n);
	left = 0;
	right = n-1;
	printf("Enter elements of the sorted array\n");
	for(i = 0 ; i < n ; i ++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element to search\n");
	scanf("%d",&element);
	result = binary_search(a,left,right,element);
	if(result != -999)
	{
		printf("%d was found in %d position in the sorted list\n",element,result);
	}
	else
	{
		printf("%d not found in list\n",element);
	}
	return 0;
}
	
