#include<stdio.h>
#include<math.h>
int* itob(int,int);
char* itoh(int,int);

int main()
{
	int n,s,s1,i;
	int *q;
	char *r;
	printf("Enter any number and number of bits to represent the number in\n");
	scanf("%d%d",&n,&s);
	s1 = s/4;	
	if(n > (pow(2,s) - 1))
	{
		printf("Insufficient number of bits\n");
	}
	else
	{	printf("The number in binary is\n");
		q = itob(n,s);
		for(i = 0; i < s ; i ++)
		{
			if(*(q+i))
			{
			putchar('1');
			}
			else
			{			
			putchar('0');
			}
			

		}
		printf("\n");		
		printf("The number in hexadecimal is\n0x");
		r = itoh(n,s);
		for(i = 0; i < s1 ; i ++)
		{
			if(*(r+i) <9 )
			printf("%d",*(r + i));
			else
			printf("%c",*(r+i));
		}		
		printf("\n");
	}
	return 0;
}
	
