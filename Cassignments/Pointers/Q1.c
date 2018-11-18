#include<stdio.h>
int main()
{
	int x[8]= {10,20,30,40,50,60,70,80};
	printf("x = %p\n (x+2) = %p \n *x = %d \n, *(x+2) = %d \n (*x+2) = %d",x,x+2,*x,*(x+2),(*x + 2));
	return 0;
}
