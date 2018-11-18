#include<stdio.h>
#define MAX 20
void bubble_sort(int arr[],int n)
{
	int i,j,flag,temp;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag == 0)
		{
			break;
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
	bubble_sort(arr,n);
	printf("after sorting\nelements are\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}	

	
