#include<stdio.h>
#include<string.h>
int indexr(char*,char);
int main()
{
	char str[30],c;
	int t;	
	printf("Enter a string\n");
	gets(str);
	printf("Enter a character\n");
	scanf("%c",&c);
	t = indexr(str,c);
	if(t > 0)
	{
		printf("%c is found at %d position (from right) in %s\n",c,t,str);
	}
	else
	{
		printf("%c not found in %s",c,str);
	}
	return 0;
}
int indexr(char* str,char c)
{
	int i;
	for(i = strlen(str)-1; i >= 0 ;i --)
	{
		if(str[i] == c)
		{
			return strlen(str) - i;
			
		}
	}
	return -1;
}
