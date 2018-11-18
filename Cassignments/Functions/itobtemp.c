#include<stdio.h>
int *disp(int a,int bits)
{
	int i,mask;
	int *p;
	int arr[bits];
	for(i=bits-1;i>0;i--)
	{
		mask=1<<i;
		arr[i] = ( a&mask ? 1 : 0);
		//putchar( a&mask ? '1' : '0');	
	}
	printf("\n");
	p=arr;
	return p;
	
}
	
int main()
{
	int a,i,bits;
	int *p;
	printf("enter a decimal \n");
	scanf("%d",&a);
	printf("enter no of bits to represent\n");
	scanf("%d",&bits);
	p = disp(a,bits);
	for(i=bits-1; i>=0; i--)
	{
		if(*(p+i) == 1)
		{
			putchar('1');
		}
		else if(*(p+i) == 0)
		{
			putchar('0');
		}
	}
	printf("\n");
	return 0;
}
