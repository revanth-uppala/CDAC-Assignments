#include<stdio.h>

void PrintReverse()
{

	char ch;
	scanf("%c",&ch);
	if(ch != '\n')
	{
		PrintReverse();
		printf("%c",ch);
	}
	
}
int main()
{
	printf("enter a string\n");
	PrintReverse();
	printf("\n");
	return 0;
}

