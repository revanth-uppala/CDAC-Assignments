#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd,ret;
	ret=mkfifo("FIFOAPI", S_IWUSR|S_IRUSR|S_IRGRP|S_IWGRP);
	if(ret == -1)
	{
		perror("fifoerr");
		exit(EXIT_FAILURE);
	}
printf("FIFO MADE!\n");
	fd = open("FIFOAPI",O_WRONLY,S_IWUSR|S_IRUSR);
	if(fd == -1)
	{
		perror("file open:");
		exit(EXIT_FAILURE);
	}
printf("FIFO OPENED!\n");	
	ret = write(fd,"Hello\n",6);
	if(ret == -1)
	{
		perror("write :");
		exit(EXIT_FAILURE);
	}
printf("WROTE IN FIFO!\n");
	close(fd);
	exit(0);	
	return 0;
}
