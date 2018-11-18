#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	char str[30];
	char c;
	int i;	
	FILE *fp = fopen(argv[1],"w+");
	printf("argc = %d,argv[1] = %s\n",argc,argv[1]);	
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(0);
	}
	printf("Enter any string\n");
	scanf("%s",str);
	printf("Writing string to file..\n");
	for(i = 0; str[i] != '\0' ; i ++ )
	{
		fprintf(fp,"%c",~str[i]);
	}
	rewind(fp);	
	printf("Entered string and Entered string in 1's complement form are\n");	
	c = fgetc(fp);
	while(c != EOF)
	{
		printf("%c",~c);
		c = fgetc(fp);
	}
	rewind(fp);	
	printf("\n");
	c = fgetc(fp);
	while(c != EOF)
	{
		printf("%c",c);
		c = fgetc(fp);
	}
	printf("\n");
	fclose(fp);	
	return 0;
}
	
		
	
	
	
