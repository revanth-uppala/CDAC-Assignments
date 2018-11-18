#include<stdio.h>
#include<stdlib.h>
void mask(int a)
{
	int mask;	
	printf("Enter mask\n");	
	scanf("%x",&mask);	
	int ch;
	printf("Enter choice:\n1.bitwise and\n2.bitwise exclusive or\n3.bitwise or\n");
	scanf("%d",&ch);
	if(ch == 1)
	{
		printf("%x & %x = %x\n",a,mask,a & mask);
	}
	else if(ch == 2)
	{
		printf("%x ^ %x = %x\n",a,mask,a ^ mask);
	}
	else if(ch == 3) 
	{
		printf("%x | %x = %x\n",a,mask,a | mask);
	}
	else
	{
		printf("Invalid choice\n");
		return;
	}	
	return;
}
void shift(int a)
{
	int shiftbits;
	printf("Enter number of bits to shift\n");
	scanf("%d",&shiftbits);	
	int ch;
	printf("Enter choice\n1.Right Shift\n2.Left Shift\n");
	scanf("%d",&ch);
	if(ch == 1)
	{
		printf("%x >> %d = %x\n",a,shiftbits,a>>shiftbits);
	}
	else if (ch == 2)
	{
		printf("%x << %d = %x\n",a,shiftbits,a<<shiftbits);
	}
	else
	{
		printf("Invalid choice\n");
		return;
	}
	return;


}	
		
int main()
{
	int a;
	int ch;
	printf("Enter any hexadecimal number\n");
	scanf("%x",&a);
	//printf("The number is %x\n ",a);
	while(1)
	{
		printf("Enter choice:\n1.Display one’s complement\n2.Carry out a masking operation\n3.Carry out a bit shifting operation\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("One's complement = %x\n",~a);
				break;
			case 2:
				mask(a);
				break;
			case 3:
				shift(a);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid input!\n");
		}
	}	
	return 0;
}
