#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFSIZE 20
int main()
{
	char buff[BUFFSIZE];	
	int fd,read_ret;
	fd = open("desdpipe",O_RDONLY);
	read_ret = read(fd,buff,BUFFSIZE);
	buff[read_ret + 1] = '\0';	
	printf("String received from Sender = %s\n",buff);
	return 0;
}
