#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

void *func1(void *str);
void *func2(void *str);

int main(int argc,char *argv[])
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,func1,(void *)argv[1]);
	pthread_create(&thread2,NULL,func2,(void *)argv[2]);
	printf("created 2 threads\n");
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
/*void *func(void *str)
{
	char *msg;
	msg=(char *)str;
	if(strcmp(msg,argv[1]) == 0 )
	{
		printf("%s from thread1\n",msg);
	}
	else if(strcmp(msg,argv[2]) == 0 )
	{
		printf("%s from thread2\n",msg);
	}
	return NULL;
}*/
void *func1(void *str)
{
	char *msg;
	msg=(char *)str;
	printf("%s\n",msg);
	return NULL;
}
void *func2(void *str)
{
	char *msg;
	msg=(char *)str;
	printf("%s\n",msg);
	return NULL;
}
