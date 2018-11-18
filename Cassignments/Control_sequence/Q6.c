/*Write a program to print ASCII values of upper case and lower case alphabets and digits (A-Z, a-z
and 0-9).*/
#include<stdio.h>
int main()
{
	char ch[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int i;
	printf("The ASCII values of characters from A-Z,a-z and 0-9 are\n");	
	for(i = 0; ch[i] != '\0' ; i++)
	{
		printf("%c = %d\n",ch[i],ch[i]);
	}
}
	
