#include<stdio.h>
#include<pthread.h>
int barrier=3;
void barrier_wait()
{
	while(barrier>0);
	return;
}
void init1()
{
	sleep(3);
	--barrier;
}
void init2()
{
	sleep(5);
	--barrier;
}
void init3()
{
	sleep(7);
	--barrier;
}
void *fun1(void *data)
{
	
	
		printf("fun1 initializing\n");
		init1();
		barrier_wait();
		printf("fun1 is ready to execute\n");
	
}
void *fun2(void *data)
{
	

		printf("fun2 initializing\n");
		init2();
		barrier_wait();
		printf("fun2 is ready to execute\n");
	
}
void *fun3(void *data)
{
	
	
		printf("fun3 initializing\n");
		init3();
		barrier_wait();
		printf("fun3 is ready to execute\n");
	
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
	
