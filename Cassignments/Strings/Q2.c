#include<stdio.h>
#include<string.h>

void strrev1( char *str)
{
	int i,l;
	l = strlen(str);	
	for(i = 0; i < (l/2) ; i ++ )
	{
		char temp;
		temp = str[i];
		str[i] = str[l- (i+1)];
		str[l - (i+ 1)] = temp;
	}
		
}

int main()
{
	char *p;	
	char str[20];
	printf("Enter a string\n");
	gets(str);
	printf("The string is\n");
	puts(str);
	strrev1(str);
	printf("The reversed string is\n");
	puts(str);
	return 0;
}	
