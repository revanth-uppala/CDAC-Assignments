#include<stdio.h>
int fact(int n)
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
	int n;
	printf("Enter any number\n");
	scanf("%d",&n);
	printf("%d! = %d",n,fact(n));
	return 0;
}

