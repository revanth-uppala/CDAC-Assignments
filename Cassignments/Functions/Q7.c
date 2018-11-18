#include<stdio.h>
int tolower(char ch)
{
	return ch - 'A' + 'a';
}
int main()
{
	char ch;
	int temp;
	printf("Enter a character\n");
	scanf("%c",&ch);
	if(ch >= 65 && ch <= 90)
	{
		temp = tolower(ch);
		printf("The character after conversion to lower case is %c\n",temp);
	}
	else
		printf("Character already in lowercase\n");
	return 0;
}
