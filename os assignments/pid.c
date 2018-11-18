#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("process id is %d\n",getpid());
	printf("parent process id is %d \n",getppid());
	return 0;
}
