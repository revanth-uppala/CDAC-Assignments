#include<stdio.h>
#include<math.h>
int main()
{
	int n,s,i;
	int *p;
	printf("Enter any number and number of bits to represent the number in\n");
	scanf("%d%d",&n,&s);
	if(n > (pow(2,s) - 1))
	{
		printf("Insufficient number of bits\n");
	}
	else
	{
		p = itob(n,s);
		for(i = 0; i < s ; i ++)
		{
			printf("%d",*(p + i));
		}
	}
	return 0;
}
	
