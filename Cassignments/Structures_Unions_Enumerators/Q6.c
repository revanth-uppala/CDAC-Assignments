#include<stdio.h>
void sum(int,int,int,int);
void diff(int,int,int,int);
void product(int,int,int,int);
void display(int,int);
void display(int r3,int i3)
{
	printf("The result is : %d + i%d",r3,i3);
}
void product(int r1,int i1,int r2,int i2)
{
	int r3,i3;
	r3 = r1*r2 - i1*i2;
	i3 = i1*r2 + i2*r1;
	display(r3,i3);
}
void sum(int r1,int i1,int r2,int i2)
{
	display(r1+r2,i1+i2);
}
void diff(int r1,int i1,int r2,int i2)
{
	display(r1-r2,i1-i2);
}

int main()
{
	enum e{a=1,b,c,d};
	int r1,i1,r2,i2,x;
	printf("Enter real and imaginary part of first complex number\n");
	scanf("%d%d",&r1,&i1);
	printf("Enter real and imaginary part of first complex number\n");
	scanf("%d%d",&r2,&i2);
	while(1)
	{	
		printf("Enter choice\n1:Sum\n2:Difference\n3:Product\n4:Quit\n");
		scanf("%d",&x);
		switch(x)
		{
			case a:
				sum(r1,i1,r2,i2);
				break;
			case b:
				diff(r1,i1,r2,i2);
				break;
			case c:
				product(r1,i1,r2,i2);
				break;
			case d:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
