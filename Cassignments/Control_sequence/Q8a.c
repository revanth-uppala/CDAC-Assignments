#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int num,digits = 0,temp,power,d,sum = 0;
	printf("Enter any number\n");
	scanf("%d",&num);
	temp = num;
	while(temp != 0)
	{
		digits++;
		temp/=10;
	}
	if(digits == 1 || num == 0)
	{
		printf("%d is not a palindrome\n",num);
		exit(0);
	}	
	power = digits - 1;
	temp = num;
	while(temp != 0)
	{
		d = temp%10;
		sum += d*pow(10,power);
		power--;
		temp /= 10;
	}
	if(sum == num)
		printf("%d is a palindrome\n",num);
	else
		printf("%d is not a palindrome\n",num);
	return 0;
}
	

