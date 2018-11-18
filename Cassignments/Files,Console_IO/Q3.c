#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2,*fp3;
	fp1 = fopen("Q31.txt","r");
	fp2 = fopen("Q32.txt","a");
	
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("Error in opening file\n");
		exit(1);
	}
	else
	{
		char c;
		
		
		c = fgetc(fp1);		
		while(c != EOF)
		{
			fputc(c,fp2);			
			c = fgetc(fp1);			
			
		}
		fclose(fp1);		
		fclose(fp2);
		fp2 = fopen("Q32.txt","r");		
		fp3 = fopen("Q33.txt","w");			
		c = fgetc(fp2);
		while(c != EOF)
		{
			fputc(c,fp3);
			c = fgetc(fp2);
		}
		
		
		
	}
	
	fclose(fp2);
	fclose(fp3);
	return 0;
}
		 
		
