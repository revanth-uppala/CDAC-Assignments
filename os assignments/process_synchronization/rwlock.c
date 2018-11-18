#include<stdio.h>
#define __USE_UNIX98
#include<pthread.h>
pthread_rwlock_t rwlock;
void *fun1(void *data)
{
	while(1)
	{
		printf("fun1 start>>outside critical section\n");
		pthread_rwlock_rdlock(&rwlock);
		printf("fun1 inside critical section\n");
		sleep(3);
		pthread_rwlock_unlock(&rwlock);
		printf("fun1 end>>outside critical section\n");
	}
}
void *fun2(void *data)
{
	while(1)
	{
		printf("fun2 start>>outside critical section\n");
		pthread_rwlock_rdlock(&rwlock);
		printf("fun2 inside critical section\n");
		sleep(3);
		pthread_rwlock_unlock(&rwlock);
		printf("fun2 end>>outside critical section\n");
	}
}
void *fun3(void *data)
{
	while(1)
	{
		printf("fun3 start>>outside critical section\n");
		pthread_rwlock_wrlock(&rwlock);
		printf("fun3 inside critical section\n");
		sleep(3);
		pthread_rwlock_unlock(&rwlock);
		printf("fun3 end>>outside critical section\n");
	}
}


int main()
{
	pthread_t read1,read2,update;
	pthread_rwlock_init(&rwlock,NULL);
	pthread_create(&read1,NULL,fun1,NULL);
	pthread_create(&read2,NULL,fun2,NULL);
	pthread_create(&update,NULL,fun3,NULL);
	pthread_join(read1,NULL);
	pthread_join(read2,NULL);
	pthread_join(update,NULL);
	pthread_rwlock_destroy(&rwlock);	
	return 0;
}
	
