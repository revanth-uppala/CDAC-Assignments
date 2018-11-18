/*Develop a C program to add two operands and store the result in one of the operand using
addition assignment operator.*/
#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter any two numbers\n");
	scanf("%d%d",&a,&b);
	a += b;
	printf("sum is %d\n",a);
	a -= b; //a original value,b original value
	if(a>b)
	{
		printf("Difference is %d\n", a -= b);
		a += b;
	}
	else
	{
		printf("Difference is %d\n", b -= a);
		b += a;
	}
	printf("Product is %d\n",a *= b);
	a = a/b; //a original value,b original value
	return 0;
}
	
	 
