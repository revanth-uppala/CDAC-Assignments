#include<stdio.h>
#define MAX 100
#define cat(a,b) a##b
int main()
{
	int k1 = 1,k2 = 5;		
	printf("## concatenated values are :%d,%d\n",cat(k,1),cat(k,2));	
	#ifdef MAX
	printf("MAX is already defined\n");
	#endif
	#ifndef MAX2
	printf("MAX2 is not defined\n");
	#define MAX2 200
	#endif
	#ifdef MAX2
	printf("MAX2 is now defined");
	#endif
	return 0;
}
	 

