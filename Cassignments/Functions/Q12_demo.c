#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int n;
	char c;
	printf("Enter any number\n");
	scanf("%d",&n);
	c = itoa(n);
	printf("The number in string form is %c\n",c);
	return 0;
}
	 
