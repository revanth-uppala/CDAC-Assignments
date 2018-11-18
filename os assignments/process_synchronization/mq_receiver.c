#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	mqd_t mqid;
	unsigned int prio=0;
	int ret=0;
	char buff[30];
	struct mq_attr mqattr;
	mqattr.mq_msgsize=30;
	mqattr.mq_maxmsg=3;
	mqattr.mq_flags=0;
	mqid=mq_open("/cmsgq",O_RDONLY,S_IRUSR|S_IWUSR,&mqattr);
	if(-1 == mqid)
	{
		perror("mq open :");
		exit(1);
	}
	ret=mq_receive(mqid,buff,30,&prio);
	if(-1 == ret)
	{
		perror("error receiving msg :");
		exit(1);
	}
	printf("received msg is %s with prio %d\n",buff,prio);
	mq_close(mqid);
	return 0;
}
