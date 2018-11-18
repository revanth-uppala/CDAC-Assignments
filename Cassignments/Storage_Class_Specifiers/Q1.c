#include<stdio.h>
int i = 5;
static int j = 10;
int main()
{
	j += 1;
	int i = 1;
	int k;
	k = foo();	
	printf("First foo: %d\n",k);	
	k = foo();
	printf("Second foo: %d\n",k);
	register int l = 20;
	printf("Inside main \n i = %d,static global variable j = %d, Register variable l = %d\n",i,j,l);
	printf("Outside main i = %d\n",k);
	return 0;
}

