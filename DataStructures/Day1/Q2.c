/*Write a program to merge two sorted arrays: A of size n, B of size m.
Merge arrays A and B to third array C of size n+m.*/
#include<stdio.h>
int main()
{
	int m,n,i,j = 0,count=0,temp;
	printf("enter sizes of 1st and 2nd array\n");
	scanf("%d%d",&m,&n);
	int arr1[m],arr2[n],arr3[m+n];
	printf("enter elements of array 1\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr1[i]);
	}
        printf("enter elements of array 2\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr2[i]);
	}
	
	for(i=0;i<n;i++)
	{
		
			arr3[i] = arr2[i];
		
	}
	for(i = n ; i < m+n ; i ++)
	{
		arr3[i] = arr1[j++];
	}
	printf("\nBefore sorting:\n");	
	for(i=0;i<m+n;i++)
	{
		printf("%d\t",arr3[i]);
	}
	printf("\n\n");
	for(i = 0 ; i < m+n- 1; i ++)
	{
		for(j = 0 ; j < (m+n-(i+1));j++)
		{
		
			if(arr3[j] > arr3[j+1])
			{
				temp=arr3[j];
				arr3[j]=arr3[j+1];
				arr3[j+1]=temp;
			}	
                }
	}
	printf("\nAfter sorting:\n");	
	for(i=0;i<m+n;i++)
	{
		printf("%d\t",arr3[i]);
	}
	
	/*for(i=0;i<m+n-count;i++)
	{
		if(arr3[i] == arr3[i+1])
		{
			count ++;
			for(j=i ; j< m+n-i +1;j++)
			{
				arr3[j]=arr3[j+1];
			}
		}
	}
	printf("\nCount = %d\n",count);*/
	printf("\nAfter merging:\n");
	for(i=0;i<m+n;i++)
	{
		printf("%d\t",arr3[i]);
	}
	return 0;
}
	
	

















			
