#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(1);
	}	
	int count = 0;
	char c;
	int ch;
	c = fgetc(fp);
	while(c != EOF)
	{
		if(c == '\n')
		{
			count++;
		}
		if(count < 20)
		{
			printf("%c",c);
		}
		else if(count >= 20)
		{
			printf("\nPress '1' to print next 20 lines,any other key to quit\n");
			scanf("%d",&ch);
			if(ch != 1)
			{
				fclose(fp);	
				printf("File closed\n");
				exit(1);
			}
			count = 0;
		}
		c = fgetc(fp);	
	}
	printf("\n\n\t~End of File~\n\n");
	fclose(fp);
	return 0;
}	
	
