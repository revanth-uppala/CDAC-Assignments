#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp = fopen("Q33.txt","r");
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(1);	
	}
	char c;
	c = fgetc(fp);
	while( c != EOF)
	{
		printf("%c",c);
		c = fgetc(fp);
	}
	fclose(fp);
	return 0;
}
	
