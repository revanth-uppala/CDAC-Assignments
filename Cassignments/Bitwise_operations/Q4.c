#include<stdio.h>
int main()
{
	int a;
	printf("Enter any number less than 64\n");
	scanf("%d",&a);
	printf("%d shifted left by 2 bits is %d\n",a,a<<2);
	printf("%d * 4 = %d\n",a,a*4);
	printf("%d shifted right by 2 bits is %d\n",a,a>>2);
	printf("%d / 4 = %d\n",a,a/4);
	return 0;
}
	
