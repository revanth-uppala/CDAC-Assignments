#include<stdio.h>
#include<string.h>
int main()
{
	char temp,str[20];
	int i,j;	
	printf("Enter any string\n");
	gets(str);
	printf("\n");
	puts(str);
	//printf("\t");
	for(i = 0; i < strlen(str) - 1; i++)
	{
		temp = str[0];
		for(j = 0 ; j < strlen(str) - 1 ; j ++)
		{		
			str[j] = str[j+1];
		}
		str[j] = temp;
		puts(str);
		//printf("\t");	
	}
	return 0;
}
	 
	
