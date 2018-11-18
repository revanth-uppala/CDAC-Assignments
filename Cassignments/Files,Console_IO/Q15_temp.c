#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp = fopen("Q15text.txt","w");
	if(fp == NULL)
	{
		printf("Error in opening file\n");
		exit(1);
	}
	char s1[] = "Hello CDAC DESD August 2018 batch!\n";	
	int i,j;
	for(i = 1 ; i <= 60; i ++)
	{
		fprintf(fp,"Line :%d  ",i);		
		for(j=0;s1[j] != '\0';j++)
		{
			printf("%c",s1[j]);
			fputc(s1[j],fp);
		}
		
	}
	printf("Lines written successfully\n");
	fclose(fp);
	return 0;
}
