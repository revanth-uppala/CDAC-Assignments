/*4. Write a menu based C program to perform operations (+, - and *) on matrices.*/
#include<stdio.h>
void sum(int a[][2],int b[][2],int ,int );
void diff(int a[][2],int b[][2],int,int);
void product(int a[][2],int b[][2],int,int);
void sum(int a[][2],int b[][2],int i,int j )
{	
	int p,q,c[i][j];
	for(p = 0; p<i; p++)
	{
		for(q = 0; q<j; q++)
		{
			c[p][q] = a[p][q] + b[p][q];
		}
	}
	for(p = 0; p<i; p++)
	{
		for(q = 0; q<j; q++)
		{
			printf("%d\t",c[p][q]);
		}
		printf("\n");
	}
}
void diff(int a[][2],int b[][2],int i,int j)
{	
	int p,q,c[i][j];
	for(p = 0; p<i; p++)
	{
		for(q = 0; q<j; q++)
		{
			c[p][q] = a[p][q] - b[p][q];
		}
	}
	for(p = 0; p<i; p++)
	{
		for(q = 0; q<j; q++)
		{
			printf("%d\t",c[p][q]);
		}
		printf("\n");
	}
}
void product(int a[][2],int b[][2],int i,int j)
{
	int p,q,c[i][j],r,sum = 0;
	
			for(p = 0; p < i; p++)
			{
				
				for(q = 0; q < j; q++)
				{
					sum = 0;
					for(r = 0; r <i;r++)
					{	
						sum += a[p][r] * b[r][p];
					}
					c[p][q] = sum;
				}
				
		
			}
	for(p = 0; p<i; p++)
	{
		for(q = 0; q<j; q++)
		{
			printf("%d\t",c[p][q]);
		}
		printf("\n");
	}
				
		
	
}
int main()
{
	int r,c,i,j;
	printf("Enter rows and columns of the matrices\n");
	scanf("%d%d",&r,&c);
	int a[r][c],b[r][c];
	printf("enter elements of 1st matrix\n");
        for(i=0;i<r;i++)
        {
       	for(j=0;j<c;j++)
	{
	scanf("%d",&a[i][j]);
	}
	}
		printf("enter elements of 2nd matrix\n");
        for(i=0;i<r;i++)
        {
       	for(j=0;j<c;j++)
	{
	scanf("%d",&b[i][j]);
	}
	}	
	int x;
	while(1)
	{	
		printf("Enter choice\n1:Sum\n2:Difference\n3:Product\n4:Quit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				sum(a,b,r,c);
				break;
			case 2: 
				diff(a,b,r,c);
				break;
			case 3: product(a,b,r,c);
				break;
			case 4: exit(0);
						
			default: printf("invalid input");
		}
	}	
	return 0;
}

		
	
		
	
