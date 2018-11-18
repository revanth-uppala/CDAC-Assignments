/*Write a program to fnd largest and smallest of n numbers without
sorting.*/
#include<stdio.h>
int main()
{
	int n,i,smallest,largest;
	printf("Enter array size\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter list of numbers\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);	
	}	
	smallest = a[0];
	largest = a[0];
	
	for(i = 0 ; i < n ; i++)
	{
		if((i+1) == n)
		{
			break;
		}		
		if(a[i] < smallest)
		{
			smallest = a[i];
		}
	}
	for(i = 0 ; i < n ; i++)
	{
		if((i+1) == n)
		{
			break;
		}

		if(a[i] > largest)
		{
			largest = a[i];
		}
	}
	printf("Smallest number = %d\tLargest number = %d\n",smallest,largest);
	return 0;
}	
	
	
