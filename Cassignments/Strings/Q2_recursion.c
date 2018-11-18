#include<stdio.h>
#include<string.h>

void strrev1( char *str,int l)
{                                                           	
	static int i,count;
       	while(count!=l/2)
		{
		for(;i< (l/2);i++)
		{	
		char temp;
		temp = str[i];
		str[i] = str[l - (i+1)];
		str[l - (i+1)] = temp;
		count ++;
    		i ++;
		strrev1(str,l);
		}
		}
}

int main()
{
	int l;	
		
	char str[20];
	printf("Enter a string\n");
	gets(str);
	l = strlen(str);	
	printf("The string is\n");
	puts(str);
	strrev1(str,l);
	printf("The reversed string is\n");
	puts(str);
	return 0;
}	
