/* Write a Program to implement strtok library function*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void strtok1(char *str,char *delim)
{
	int i,j,k = 0;
	
		
	char *ret[strlen(delim) + 1];	
		ret[0] = str;
		k++;
		for(i = 0 ; i < str[i] != '\0'  ; i ++)
		{
			for( j = 0; j < delim[j] != '\0'; j ++)
			{
				if(str[i] == delim[j])
				{
					ret[k] = &str[i + 1];
										
					k ++;					
					str[i] = '\0';
					break;
				}
			
			}
		}
		ret[k] = '\0';
		//return ret;
		printf("\n");		
		
		for(i = 0; ret[i] != '\0' ; i++)
		{
			printf("%s\n",ret[i]);
		} 	
		
}	
		
	

int main()
{
	char str[20],delim[10];
	char *p;	
	int i;	
	printf("Enter any string\n");
	scanf("%s",str);
	//fflush(stdin);
	printf("Enter delimiters\n");
	scanf("%s",delim);
	printf("The string after breaking into tokens is\n");	
	strtok1(str,delim);	
	/*for(i = 0; p + i != '\0' ; i++)
	{
			printf("%s\n",*(p + i));
	} */
		
	return 0;
}
	
