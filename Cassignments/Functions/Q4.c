#include<stdio.h>
int right(int n,int b)
{
	return n >>= b;
}
int main()
{
	int n,b;
	printf("Enter a number 'n' and number of times to shift n\n");
	scanf("%d%d",&n,&b);
	printf("Before shifting : %d\nAfter shifting : %d\n ",n,right(n,b));
	return 0;
} 
	
