/*#include<stdio.h>
#include<string.h>
int* itob(int n,int s)
{
	int val[s];
	int i;
	
		
	for( i = 0; i <= s-1  ; i++)
	{
		val[i] = n%2;
		n = n/2;
		//printf("%d",val[i]);
		
	}
	
	return val;
	
	
	
	
}
int main()
{
	int n,s,i;
	int *p;
        printf("Enter any integer and the number of bits for binary representation\n");
	scanf("%d%d",&n,&s);
        p = itob(n,s);
	printf("After converting to binary the number is \n ");	        
	for( i = 0; i < s ; i++)
	{
		printf("%d",*(p+i));
	}
	return 0;
}
	
	

	
	
