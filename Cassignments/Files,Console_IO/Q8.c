#include<stdio.h>
long int fact(int n)
{
	int f=1;	
	if(n == 1 || n == 0)
	{
		return 1;
	}
	else
		return n*fact(n-1);
		
}
int main()
{
	int n,i;
	l1:printf("Enter any number greater than or equal to 3\n");
	scanf("%d",&n);
	if(n<3)
	{
		printf("Invalid input\n");
		goto l1;		
	}
	for(i = 1; i <= n ; i ++)
	{
		printf("%dp%d = %ld\n",n,i,(fact(n)/fact(n-i)));
	}
	return 0;
}
	
	
