/*Write a function “merge_sort” to implement Merge sort. Pass array
“arr” and size “n” as arguments from main*/
#include<stdio.h>
#define MAX 20
void merge(int arr[],int temparr[],int Lpos,int Rpos,int RightEnd)
{
	int i,LeftEnd,NumElements,temppos;
	LeftEnd = Rpos - 1 ; /*Center*/
	temppos = Lpos;		
	NumElements = RightEnd - Lpos + 1;
	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(arr[Lpos] <= arr[Rpos])
		{
			temparr[temppos++] = arr[Lpos++];
		}
		else
		{
			temparr[temppos++] = arr[Rpos++];
		}
	}
	while(Lpos <= LeftEnd)
	{
		temparr[temppos++] = arr[Lpos++];
	}
	while(Rpos <= RightEnd)
	{
		temparr[temppos++] = arr[Rpos++];
	}
	for(i = 0; i < NumElements; i ++,RightEnd--)
	{
		arr[RightEnd] = temparr[RightEnd];
	}
}
	
			 

void msort(int arr[],int temparr[],int left,int right)
{
	int center;
	if(left<right)
	{
		center = (left + right)/2;
		msort(arr,temparr,left,center);
		msort(arr,temparr,center + 1,right);
		merge(arr,temparr,left,center + 1,right);
	}
}

void merge_sort(int arr[],int n)
{
	int left,right,temparr[MAX];	
	left = 0;
	right = n - 1;
	msort(arr,temparr,left,right);
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
	
	merge_sort(arr,n);
	printf("after sorting\nelements are\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}	

	
