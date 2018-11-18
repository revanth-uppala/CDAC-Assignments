#include<stdio.h>
int main()
{
	int n;
	printf("enter a number\n");
	scanf("%d",&n);
	if(n<1)
	{
	printf("ERROR\n");
	exit(1);
	}
	printf("initial value is %d\n",n);
	while(n>1)
	{
		if(n%2==0)
		{
			n/=2;	
			if(n!=1)
			printf("next value is %d\n",n);
		}
		else
		{
			n=n*3+1;
			if(n!=1)		
                        printf("next value is %d\n",n);
		}
	}
	printf("final value is %d\n",n);
	return 0;
}
