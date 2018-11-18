#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<linux/in.h>
#include<stdlib.h>

int main(int argc,char argv[])
{
	int sfd,new_sfd,bind_ret,rw_ret;
	char buff[100];
	pid_t childpid;
	struct sockaddr_in serv_addr,cli_addr;
	socklen_t cli_len;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sfd)
	{
		perror("socket open:");
		exit(1);
	}
	bzero((char *)&serv_addr,sizeof(serv_addr));    //clears struct var
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(20000);
	bind_ret=bind(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(-1 == bind_ret)
	{
		perror("bind:");
		exit(1);
	}
	listen(sfd,2);
	cli_len=sizeof(cli_addr);
	
	while(1)
	{
		new_sfd=accept(sfd,(struct sockaddr*)&cli_addr,&cli_len);
		if(-1 == new_sfd)
		{
			perror("accepting");
			exit(1);
		}
		printf("connected to %s:%d\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));
		
		childpid=fork();
		if(0 == childpid)
		{
		//	close(sfd);
			while(1)
			{
				bzero(buff,100);                  //clears buffer
				rw_ret=read(new_sfd,buff,100);
				if(-1 == rw_ret)
				{
					perror("read");
					exit(1);
				}
				printf("client:    %s\n",buff);
				if(strncmp("bye",buff,3) == 0)
				{
					printf("disconnected from %s:%d\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));
					
				}
				bzero(buff,100);
				read(0,buff,100);
				rw_ret=write(new_sfd,buff,strlen(buff));
				if(-1 == rw_ret)
				{
					perror("write");
					exit(1);		
				}		
				
			}
		}
	}
	
				
	close(sfd);
	close(new_sfd);
	return 0;
}
		
		
		
