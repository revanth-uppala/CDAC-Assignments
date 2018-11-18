/*Write a program last that prints the last n lines of its text input. By default n should be 5, but
your program should allow an optional argument so that
last -n
prints out the last n lines, where n is any integer. Your program should make the best use of
available storage. (Input of text could be by reading a file specified from the command or reading
a file from standard input)*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	FILE *fp = fopen(argv[1],"r");
	printf("%s",argv[1]);	
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(1);
	}
	char c;
	int n,lines = 0,count = 0;
	printf("Enter n value\n");
	scanf("%d",&n);
	c = fgetc(fp);
	while(c != EOF)
	{
		if(c == '\n')
		{
			lines++;
		}
		c = fgetc(fp);
	}
	printf("total lines = %d\n",lines);
	rewind(fp);
	c = fgetc(fp);
	
	while(c != EOF)
	{
		if(c == '\n')
		{
			count++;
			if(count >= lines - n)
			{
				while(c != EOF)				
				{				
					printf("%c",c);
					c = fgetc(fp);
				}
				exit(1);
			}
		}
		c = fgetc(fp);
	}	
	return 0;
}
	
