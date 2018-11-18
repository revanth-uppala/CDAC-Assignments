#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of numbers to be stored\n");
	scanf("%d",&n);
	int i,ar[n];
	for(i = 0; i < n; i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&ar[i]);
	}
	for(i = 0; i < n; i++)
	{
		printf("a[%d] = %d\n",i,ar[i]);
		
	}
	return 0;
}
	
