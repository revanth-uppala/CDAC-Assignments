#include<stdio.h>
#include<string.h>
int replace(char*);
int main()
{
	char str[80];
	int count;
	printf("Enter any string\n");
	gets(str);
	count = replace(str);
	printf("Number of spaces replaced = %d\n",count);
	printf("Modified string is :%s\n",str);
	return 0;
}
int replace(char* str)
{
	int i,count = 0;
	for(i = 0;i < strlen(str) ; i++)
	{
		if(str[i] == ' ')
		{
			str[i] = '-';
			count ++;
		}
	} 
	
	return count;
}
	
	
