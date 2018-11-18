/*3. Write a C program to find the maximum of 2 numbers using Conditional operator.*/
#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two numbers\n");
	scanf("%d%d",&a,&b);
	a>b ? printf("Larger number is %d\n",a) : printf("Larger number is %d\n",b);
	return 0;
}
	
