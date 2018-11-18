#include<stdio.h>
#include<string.h>
void invertponwards(int n,int p,int b)
{
	int s = 8;	
	int val[s];
	int i,m;
	for( i = 0; i <= s-1  ; i++)
	{
		val[i] = n%2;
		n = n/2;
		//printf("%d",val[i]);
		
	}
	printf("After converting to binary the number is \n ");	
	for( m = i-1 ; m>=0 ; m--)
	{
		printf("%d",val[m]);
	} 
	
	for( int j = p ; j< p+b ; j++)
	{
		val[j] =  ! val[j];
	} 	
	printf("\nAfter inverting the number is \n ");
	for( int k = i-1 ; k>=0 ; k--)
	{
		printf("%d",val[k]);
	} 		
		
}
int main()
{
	int n,p,b;
        printf("Enter any integer,position and the number of bits to invert \n");
	scanf("%d%d%d",&n,&p,&b);
        invertponwards(n,p,b);
        return 0;
}
	
	

	
	
