#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#define SHM_SIZE 100
int main(int argc,char *argv[])
{
	int shmid;
	key_t key;
	char *shm;
	//char buff[30];
	key=123;
	shmid=shmget(key,SHM_SIZE,IPC_CREAT|0666);
	if(shmid < 0)
	{
		perror("shmget:");
		exit(1);
	}
	shm=shmat(shmid,NULL,0);
	if(shm == (char*) -1)
	{
		perror("shmat:");
		exit(1);
	}	
	//strcpy(buff,argv[1]);
	memcpy(shm,"hello,sender here!!\0",20);
	while(*shm != '$');
	return 0;
}
		
