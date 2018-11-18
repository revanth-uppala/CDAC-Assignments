#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<linux/in.h>
#include<stdlib.h>
#include <netdb.h>

int main(int argc,char *argv[])
{
	int sfd,rw_ret,con_ret;
	char buff[100];
	struct sockaddr_in serv_addr;
	struct hostent *server;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sfd)
	{
		perror("socket open:");
	}
	server=gethostbyname(argv[1]);     //get details of host through ipaddr
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	bcopy((char *)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);    //copy ipaddr of host to serv_addr
	serv_addr.sin_port=htons(3333);               //port same as host
	con_ret=connect(sfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	if(-1 == con_ret)
	{
		perror("connecting:");
	}
	while(1)
	{
		bzero(buff,100);              //clears buffer
		read(0,buff,100);
		rw_ret=write(sfd,buff,strlen(buff));
		if(-1 == rw_ret)
		{
			perror("write");
		}       
		bzero(buff,100);       
		rw_ret=read(sfd,buff,100);
		if(-1 == rw_ret)
		{
			perror("read");
		}
		printf("server:    %s\n",buff);
		
		
		if(strncmp("bye",buff,3) == 0)
		{
			break;
		}
	}
	close(sfd);
	return 0;
}
		
		
		
