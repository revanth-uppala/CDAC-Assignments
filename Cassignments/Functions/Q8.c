#include<stdio.h>
#include "fact.h"
int main()
{
	int n,r;
	printf("Enter values of n and r\n");
	scanf("%d%d",&n,&r);
	printf("%dp%d = %d\n",n,r,fact(n)/fact(n-r));
	printf("%dc%d = %d\n",n,r,fact(n)/(fact(n-r)*fact(r)));	
	return 0;
}
