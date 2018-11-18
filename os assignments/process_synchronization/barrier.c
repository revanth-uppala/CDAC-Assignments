#include<stdio.h>
//#define __USE_XOPEN2K
#include<pthread.h>
pthread_barrier_t initbar;
void *fun1(void *data)
{
	
	
		printf("fun1 initializing\n");
		sleep(3);
		pthread_barrier_wait(&initbar);
		printf("fun1 is ready to execute\n");
	
}
void *fun2(void *data)
{
	

		printf("fun2 initializing\n");
		sleep(5);
		pthread_barrier_wait(&initbar);
		printf("fun2 is ready to execute\n");
	
}
void *fun3(void *data)
{
	
	
		printf("fun3 initializing\n");
		sleep(7);
		pthread_barrier_wait(&initbar);
		printf("fun3 is ready to execute\n");
	
}


int main()
{
	pthread_t read1,read2,update;
	pthread_barrier_init(&initbar,NULL,3);
	pthread_create(&read1,NULL,fun1,NULL);
	pthread_create(&read2,NULL,fun2,NULL);
	pthread_create(&update,NULL,fun3,NULL);
	pthread_join(read1,NULL);
	pthread_join(read2,NULL);
	pthread_join(update,NULL);
	pthread_barrier_destroy(&initbar);
	return 0;
}
	
