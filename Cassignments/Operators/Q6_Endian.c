/*6. Write a program to find whether the given processor is little endian or big endian*/
#include<stdio.h>
int main()
{
	int x = 1;
	char *p = (char*)&x;
	printf("*p = %d\n",*p);	
	if(*p & x)
	{	
		printf("Little Endian\n");
		
	}	
	else
		printf("Big Endian\n");
	return 0;
}
	
