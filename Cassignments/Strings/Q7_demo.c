#include <stdio.h>
#include <string.h>
int main()
{
	char str[30];
	char *temp;
	char *delim = " ";
	/*printf("Enter delimiter string\n");
	scanf("%s",delim);*/
	printf("Enter a string\n");
	scanf("%s",str);
	printf("The string after being broken into tokens is\n");
	temp = strtok(str,delim);
	while(temp != NULL)
	{
		printf("%s ",temp);
		temp = strtok(NULL,delim);
	}
	printf("\n");
	return 0;
}
	
