/*Develop a C program to calculate simple interest using the formula I=PTR/100. Display Interest
with two digit precision after decimal point*/
#include<stdio.h>
#include<stdlib.h>
void calc();
void calc()
{
	int P,T;
	float R,I;	
	printf("Enter Principal,Time(in years) and Rate of Interest\n");
	scanf("%d%d%f",&P,&T,&R);
	I = (P*T*R)/100;
	printf("Interest is %.2f and Amount is %.2f\n",I,I+P);
}

int main()
{
	int c;
	while(1)
	{	
		printf("1:Calculate\n2:Quit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				calc();
				break;
			case 2:
				exit(0);
			default:printf("Invalid input\n");
		}
				
	}	
	return 0;
}
