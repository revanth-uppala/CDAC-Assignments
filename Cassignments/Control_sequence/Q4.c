/*Develop a C program to find factorial of a number N using for loop.*/
#include<stdio.h>
int main()
{
   long int fact=1;
   int num,i;
   printf("enter a number\n");
   scanf("%d",&num);
   for(i=num;i>0;i--)
   fact*=i;
   printf("factorial of %d is %ld\n",num,fact);
   return 0;
}

