/*Develop a C program to find sum of all odd numbers upto N using while loop.*/
#include<stdio.h>
int main()
{
  int limit,i=1,sum=0;
  printf("enter limit of odd numbers\n");
  scanf("%d",&limit);
  printf("odd numbers from 1 to limit are\n");
  while(i<=limit)
  {
   sum+=i;
   printf("%d\n",i);
   i+=2;
   }
   printf("sum of odd numbers is %d\n",sum);
  return 0;
}
