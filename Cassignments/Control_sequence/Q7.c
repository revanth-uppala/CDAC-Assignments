/*Write a Program to find if a given number is Armstrong number.
Hint: (153 = 1^3 + 5^3 + 3^3)*/
#include<stdio.h>
#include <math.h>
int main()
{
    int num,digits=0,rem,sum=0,temp;
    printf("enter a number\n");
    scanf("%d",&num);
    temp=num;
    while(temp!=0)
    {
      temp/=10;
      digits++;
    }
   temp=num;
   while(temp!=0)
   {
    rem=temp%10;
    sum+=pow(rem,digits);
    temp/=10;
   }
  if(sum==num)
  printf("%d is an armstrong number\n",num);
  else
  printf("%d is not an armstrong number\n",num);
  return 0;
} 

	

