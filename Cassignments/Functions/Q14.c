#include<stdio.h>
#include<stdlib.h>
long int fact(int a)
{
	if(a==0 || a==1)
	{
		return 1;
	}
	else
	{
		return a*fact(a-1);
	}
}
int hcf(int a,int b)
{
	int rem,temp;
	if(b == 0)
	{
		return a;
	}  	
	if(a>b)
  	{
  	
			    			
			rem=a%b;
    			hcf(b,rem);
  		
		
  	}
  	else if(b>a) 
  	{
		
						
			rem=b%a;
    			hcf(a,rem);
			
		
  	} 
   	
  	else if(a==b)
  	{ 
   		return a;
  	}
	
 }	
int main()
{
	int c,result,a,b;
	while(1)
	{
		printf("Enter choice\n1:factorial\n2:GCD\n3:Quit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("Enter the number\n");
			scanf("%d",&a);
			result = fact(a);
			break;
			case 2:
			printf("Enter the two numbers\n");
			scanf("%d%d",&a,&b);
			result = hcf(a,b);
			break;
			case 3:
			exit(0);
			default: printf("Invalid Input");
		}
		printf("The result is %d\n",result);
	}
	return 0;
}

