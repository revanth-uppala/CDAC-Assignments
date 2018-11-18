/*Write a program to find whether given number is palindrome or not.*/
#include<stdio.h>
#include<math.h>
int main()
{
	int num,rem,sum=0,temp;
	printf("Enter any number\n");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
	rem=temp%10;
	sum=sum*10+rem;
	temp/=10;
	}
  if(sum==num)
  printf("%d is a palindrome\n",num);
 else
  printf("%d is not a palindrome\n",num);
 return 0;
}
  
	
	
