#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	FILE *fp = fopen(argv[1],"r");
	char c;
	char ch;	
	int count = 0;		
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(1);
	}	
	c = fgetc(fp);
	while(c != EOF)
	{
		if(c == '\n')
		{
			count ++;
		}
		printf("%c",c);
		
		if(count > 20)
		{
			printf("Press p to print next 20 lines,any other key to quit\n");
			scanf("%c",&ch);
			if(ch == 'p')
			{
				continue;
			}
			else
			{
				fclose(fp);
				printf("File closed succesfully\n");				
				exit(1);
			}
		}
		c = fgetc(fp);
	}
	printf("\n\tNo other lines to print\n\t");
	fclose(fp);
	return 0;
}
			
		
