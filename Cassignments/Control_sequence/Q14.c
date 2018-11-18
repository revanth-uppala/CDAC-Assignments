/*Write a C program to generate two Relatively Prime numbers.*/
#include<stdio.h>
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
  	{ 
   		return a;
  	}
	
 }	


int main()
{
  int a,b,limit,x;
  printf("enter limit\n");
  scanf("%d",&limit);
  printf("relative primes between 1 to %d are:\n",limit);
  for(a= 1 ;a<=limit;a++)
  {
  	for(b=1; b<=limit;b++)
  	{
   		x = hcf1(a,b);
		if(x	== 1)
   		{
    			printf("%d %d\n",a,b);
   		}
		
  	}
  }
return 0;
}
	
