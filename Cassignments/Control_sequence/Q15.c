/*Write a program to generate Random number
Any
Prime number
Two Relatively Prime Numbers*/
#include<stdio.h>
#include<stdlib.h>
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
int hcf1(int a,int b)
{
	int rem,temp;
	if(b == 0)
	{
		return a;
	}  	
	if(a>b)
  	{
  		rem=a%b;
    		hcf1(b,rem);
  	}
  	else if(b>a) 
  	{
		rem=b%a;
    		hcf1(a,rem);
	} 
   	
  	else if(a==b)
 		return a;
} 
int main()
{
	int c,i,j,factors = 0;	
		
	while(1)
	{	
		int rand1;		
			
		l1:printf("Enter choice:\n1:calculate\n2:Quit");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			rand1 = rand()/10000;
			printf("Random  number = %d\n", rand1);
			while(1)
			  {			
				rand1 = rand()/10000;				
				if(isprime(rand1))
				{
					printf("Random prime number = %d\n",rand1);
					break;
				}
			  }
			for( i = rand1; i > 1 ; i --)
			{
				for(j = rand1 - 2; j > 1 ; j --)
				{
					if(hcf1(i,j) == 1)
					{
						printf("2 random relatively prime numbers are %d and %d\n",i,j);
						goto l1;
					}
				}
			}
			break;
			case 2:
			exit(0);
			default: printf("Invalid input\n");
		}
	}
	return 0;
}
