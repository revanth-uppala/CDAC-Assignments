/*1. Develop a C program to perform operations (+,*,-, / and %) on two whole numbers. Identify
suitable data types to represent the numbers and resultant values*/
#include<stdio.h>
int main()
{
	int a,b,modu;
	float quotient;
	int sum,diff,product;
	printf("Enter any two numbers\n");
	scanf("%d%d",&a,&b);	
	sum = a + b;
	if(a>b)	
	{		
		diff = a - b;	
	}
	else
	{		
		diff = b - a;	
	}	
	quotient = (float)a/b;
	modu = a%b;
	product = a*b;
	printf("sum is %d\n",sum);
	printf("diff is %d\n",diff);
	printf("product is %d\n",product);
	printf("Modulus is %d\n",modu);
	printf("Quotient is %f\n",quotient);
	return 0;
}

	
