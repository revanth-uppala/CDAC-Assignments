#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t id;
	id=fork();
	if(id == -1)
	{
		perror("fork:");
	}
	else if(id == 0)
	{
		printf("i am child process\n");
		printf("pid:%d\nppid:%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("i am parent process\n");
		printf("pid:%d\nppid:%d\n",getpid(),getppid());
		sleep(1);
	}
	return 0;
}
		
	
