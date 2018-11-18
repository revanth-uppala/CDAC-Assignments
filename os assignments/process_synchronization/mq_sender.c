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
	int prio=0,ret=0;
	char buff[30];
	struct mq_attr mqattr;
	mqattr.mq_msgsize=30;
	mqattr.mq_maxmsg=3;
	mqattr.mq_flags=0;
	mqid=mq_open("/cmsgq",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR,&mqattr);
	if(-1 == mqid)
	{
		perror("mq open :");
		exit(1);
	}
	//while(1)
	//{
		printf("enter msg to send\n");
		scanf("%[^\n]s",buff);
		ret=mq_send(mqid,buff, strlen(buff) ,prio);
		if(-1 ==ret)
		{
			perror("msg sending error");
			exit(1);
		}
		mq_close(mqid);
	//}
	return 0;
}
