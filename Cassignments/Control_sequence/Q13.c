/*Write a program to find the sum of digits of a given number.*/
#include<stdio.h>
int main()
{
	int num,rem,sum=0,temp;
	printf("Enter any number\n");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
	rem=temp%10;
	sum += rem;
	temp/=10;
	}
	printf("Sum of digits of %d is %d\n",num,sum);
	return 0;
}
