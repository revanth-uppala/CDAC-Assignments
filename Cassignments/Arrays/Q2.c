#include<stdio.h>
#include<string.h>
int main()
{
	char text[80];
	int i,letters = 0,digits = 0, blanks = 0, tabs= 0;
	printf("Enter any text\n");
	gets(text);
	for(i= 0;text[i] != '\0';i++)
	{
		if((text[i] >= 65 && text[i] <= 90 ) ||(text[i] >= 97 && text[i] <= 122))
		{
			letters++;
		}
		else if(text[i] >= 48 && text[i] <= 57)	
		{	
			digits++;
		}
		else if(text[i] == 32)
		{
			blanks++;
		}
		else if(text[i] == 9)
		{
			tabs++;
		}
	}
	printf("Letters = %d\nDigits = %d\nBlanks = %d\nTabs = %d\n",letters,digits,blanks,tabs);
	return 0;
}
