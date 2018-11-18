#include<stdio.h>
int hcf(int a,int b)
{
	int rem,temp;
  	if(a>b)
  	{
  		while(rem!=0)
  		{
			temp = b;    			
			rem=a%b;
    			a=b;
    			b=rem;
  		}
  		return temp;
  	}
  	else if(b>a) 
  	{
		while(rem!=0)
		{   		
			temp = a;			
			rem=b%a;
    			b=a;
    			a=rem;
		}	
		return temp;
  	}
   	
  	else if(a==b)
  	{ 
   		return 5;
  	}
 }
int main()
{
	int a,b;
	printf("Enter two numbers\n");
	scanf("%d%d",&a,&b);
	printf("The hcf is %d",hcf(a,b));
	return 0;
}
