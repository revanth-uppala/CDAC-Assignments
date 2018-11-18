/*10. Generate the following pyramid of numbers using nested loops
1
212
32123
4321234
543212345*/
#include<stdio.h>
int main()
{
	int i,j,k,l;
	for(i = 1; i <= 5; i++)
	{
		for(j = 5; j >i; j--)
		{
			printf(" ");
		}
		for(k = i; k >= 1; k--)
		{
			printf("%d",k);
		}
		for(l = i ; l>1 ; l--)
		{
			printf("%d",l);
		}
		printf("\n");
	}
	return 0;
}
		
