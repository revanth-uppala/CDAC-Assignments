#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	int fd;
	fd = open("desdpipe",O_WRONLY);
	write(fd,argv[1],strlen(argv[1]));
	close(fd);
	return 0;
}
