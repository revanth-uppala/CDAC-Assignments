#include<stdio.h>
int isprime(int rand1)
{
	int i,factors = 0;	
	for(i = 1; i <= rand1 ; i++)
	{
		if(rand1 % i == 0)
		{
				factors++;
		}
	}
		if(factors == 2)
		{
			return 1;
		}
		else
			return 0;
	
}
int main()
{	int a;
	printf("Enter any number\n");
	scanf("%d",&a);
	printf("%d",isprime(a));
	return 0;
}
