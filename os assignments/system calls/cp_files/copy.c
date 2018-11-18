#include<stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define MAX 128

int main(int argc,char *argv[])
{
	char buff[MAX];	
	int fdr,fdw,read_ret,write_ret,x;
	fdr=open(argv[1],O_RDONLY, S_IRUSR);
	if(fdr == -1)
	{
		perror("error: ");
	}
	else
	{
		read_ret = read(fdr,buff,MAX);
		printf("Characters read = %d\n",read_ret);		
		if(read_ret == -1)
		{
			perror("Error: ");
		}
		else
		{
			x=close(fdr);
			if(x==-1)
			{
				perror("error:");
			}
		}
	}
	fdw=open(argv[2],O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	if(fdw == -1)
	{
		perror("error:");
	}
	else
	{
		write_ret=write(fdw,buff,read_ret);
		if(write_ret == -1)
		{
			perror("Error: ");
		}
		else
		{
			x=close(fdw);
			if(x==-1)
			{
				perror("error:");
			}
		}
	}
	return 0;
}
