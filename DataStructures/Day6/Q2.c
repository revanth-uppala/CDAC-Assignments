#include<stdio.h>
#define MAX 20
void insertion_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<=n-1;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0 && arr[j]>temp ;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
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
	insertion_sort(arr,n);
	printf("after sorting\nelements are\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}	

	
