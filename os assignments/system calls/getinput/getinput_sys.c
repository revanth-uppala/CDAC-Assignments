#include<stdio.h>
#include <unistd.h>
#include <errno.h>

#define MAX 50
int main()
{
	char buff[MAX];
	int read_ret,write_ret;
	read_ret = read(0,buff,MAX);
	if(read_ret == -1)
	{
		perror("Error:");
	}
	else
	{
		write_ret = write(1,buff,read_ret);
	}
	return 0;
}
