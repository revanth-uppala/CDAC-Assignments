#include<stdio.h>
#include "fact.h"
int main()
{
	int i;
	float sum = 0;
	for(i = 1;i<=7;i++)
	{
		if(i%2 == 0)
		{
			sum += (float)i/fact(i);
		}
		else
		{
			sum -= (float)i/fact(i);
		}
	}
	printf("-1 / 1! + 2 / 2! –3 /3! + 4 / 4! - 5 / 5! + 6 / 6! - 7 / 7! = %.2f\n",sum); 	
	return 0;
}
