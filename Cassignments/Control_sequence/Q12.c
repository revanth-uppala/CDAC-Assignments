/*Write a program to print all the prime numbers in the first N numbers*/
#include<stdio.h>
int main()
{
	int limit,i,factors=0,j;
	printf("Enter limit\n");
	scanf("%d",&limit);
	printf("Prime numbers from 1 to %d are :\n",limit);	
	for(i = 1; i <= limit ; i++)
	{
		factors = 0;		
		for(j = 1; j <= limit ; j++)
		{
			if(i%j == 0)
			{
				factors++;
			}
		}
		if(factors == 2)
		{
			printf("%d\n",i);
		}
		else
			continue;
	}
	return 0;
}
			
