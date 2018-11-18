#include<stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#define BUFFSIZE 20
int main()
{
	int fd,read_ret;
	char buff[BUFFSIZE];
	fd = open("FIFO.txt",O_RDONLY);	
	while( fd == -1)
	{
		fd = open("FIFO.txt",O_RDONLY);
	}
	read_ret = read(fd,buff,BUFFSIZE);
	buff[read_ret + 1] = '\0';
	printf("String received = %s\n",buff);
	close(fd);
	return 0;
}
