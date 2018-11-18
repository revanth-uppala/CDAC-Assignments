#include<stdio.h>
int* itob(int n,int s)
{
	int val[s];
	int i;
	int *p;
	for( i = s-1; i >= 0   ; i--)
	{
		val[i] = n%2;
		n = n/2;
	}
	p = val;
	return p;
}
int main()
{
	int num,i,count=0;
	int* p;
	printf("enter a number\n");
	scanf("%d",&num);
	p=itob(num,8);
	for(i=0;i<8;i++)
	{
		if(p[i] == 1)
		count++;
 	}
	printf("number of 1's in 8 bit binary representation of %d is %d\n",num,count);
}	
	
