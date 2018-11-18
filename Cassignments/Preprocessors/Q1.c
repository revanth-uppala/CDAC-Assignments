#include<stdio.h>
#define f(n) a
#define a fact(n)

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
	int n;
	printf("Enter any number\n");
	scanf("%d",&n);
	printf("%d! = %ld",n,f(n));
	return 0;
}

