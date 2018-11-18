#include<stdio.h>
#include<pthread.h>
void *fun1(void *data)
{
	while(1)
	{
		printf("fun1 start>>outside critical section\n");
		printf("fun1 inside critical section\n");
		sleep(3);
		printf("fun1 end>>outside critical section\n");
	}
}
void *fun2(void *data)
{
	while(1)
	{
		printf("fun2 start>>outside critical section\n");
		printf("fun2 inside critical section\n");
		sleep(3);
		printf("fun2 end>>outside critical section\n");
	}
}
void *fun3(void *data)
{
	while(1)
	{
		printf("fun3 start>>outside critical section\n");
		printf("fun3 inside critical section\n");
		sleep(3);
		printf("fun3 end>>outside critical section\n");
	}
}


int main()
{
	pthread_t read1,read2,update;
	pthread_create(&read1,NULL,fun1,NULL);
	pthread_create(&read2,NULL,fun2,NULL);
	pthread_create(&update,NULL,fun3,NULL);
	pthread_join(read1,NULL);
	pthread_join(read2,NULL);
	pthread_join(update,NULL);
	return 0;
}
	
