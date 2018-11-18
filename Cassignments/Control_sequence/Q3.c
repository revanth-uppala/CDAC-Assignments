
/*Develop a C program which adds all numbers from 1 to N, except those which are divisible by 5.
Implement this using for loop and continue statement.*/
#include<stdio.h>
int main()
{
	int n,i,sum = 0;
	printf("Enter value of N\n");
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
	{
		if(i%5 == 0)
			continue;
		else
			sum += i;
	}
	printf("The sum from 1 to %d except those numbers which are divisible by 5 is %d\n",n,sum);
	return 0;
}
	
