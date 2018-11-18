#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch1,ch2,found;
	found = 'n';	
	FILE *fp;
	FILE *fp2;
	char str,str2;	
	fp=fopen("myfile1.txt","r");
	fp2=fopen("myfile2.txt","w");
	if(fp == NULL)
	{
	printf("error in opening file\n");
	exit(1);
	}	
	if(fp2 == NULL)
	{
        printf("error in opening file\n");
	exit(1);
	}
	else
	{
		ch1=fgetc(fp);
		ch2=fgetc(fp);
	while(ch2 != EOF )
	{
		
		if((ch1=='/' && ch2=='*')) 
		{
			found = 'y';						
		
		}
		if(ch1 == '/' && ch2 == '/')
		{
						
			while(ch2 != '\n')
			{
				
				ch2 = fgetc(fp);
			}			
			ch1 = ch2;
			
		}
		
		if(found == 'n')
		{
			fputc(ch1,fp2);
		}
		if(ch1 == '*' && ch2 == '/')
		{
			found = 'n';
			ch2 = fgetc(fp);
		}
		ch1 = ch2;
		ch2 = fgetc(fp);
	}
	}
fclose(fp);
fclose(fp2);
return 0;
}
