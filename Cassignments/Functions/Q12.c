/*12. Write a C program with a recursive function itoa, which converts integer into a string.*/
#include<stdio.h>
#include<string.h>
char* itoa(int n)
{	
	static char ch[5];
	char *p;
	static int i = 0;
	if(n != 0)
	{
		ch[i++] = n % 10;
			
		itoa(n/10);
	}
	else
	{	p = ch;
		return p;
	}
}
int main()
{
	int n,i;
	char *q;	
	printf("Enter any number\n");
	scanf("%d",&n);
	q = itoa(n);
	//printf("\n%c\n",q);	
	printf("%d after converting to string is \n",n);	
	for(i = strlen(q) - 1 ; i >= 0; i --)
	{
		printf("%d",*(q+i));
	}
	printf("\n");
	return 0;
}

	
	
