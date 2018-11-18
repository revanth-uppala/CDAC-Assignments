#include<stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define MAX 128
int main()
{
	char str[MAX];
	printf("enter a string\n");
	scanf("%[^\n]s",str);
	write(1,str,strlen(str));
	printf("\n");
	
	return 0;
}
