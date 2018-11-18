#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
       #include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd;
	fd = open("FIFO.txt",O_CREAT | O_WRONLY);
	if(fd == -1)
	{
		perror("file open:");
	}	
	write(fd,argv[1],strlen(argv[1]));
	//close(fd);
	return 0;
}
