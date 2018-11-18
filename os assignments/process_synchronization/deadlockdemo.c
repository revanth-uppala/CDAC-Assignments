#include <stdio.h>
#include <pthread.h>
int count;
pthread_mutex_t countmutex;
void *incThread(void *data)
{
	while(1)
	{
		pthread_mutex_lock(&countmutex);   //lock
		pthread_mutex_lock(&countmutex);   //lock
		count++;
		printf("incthread: %d\n",count);
		pthread_mutex_unlock(&countmutex);   //unlock
		pthread_mutex_unlock(&countmutex);   //unlock
	}
	
}
void *decThread(void *data)
{
	while(1)
	{
		pthread_mutex_lock(&countmutex);   //lock
		pthread_mutex_lock(&countmutex);   //lock
		count--;
		printf("decthread: %d\n",count);
		pthread_mutex_unlock(&countmutex);   //unlock
		pthread_mutex_unlock(&countmutex);   //unlock
	}
	
}
int main()
{
	
	pthread_t id_inc,id_dec;
	pthread_mutex_init(&countmutex,NULL);      //init	
	pthread_create(&id_inc,NULL,incThread,NULL);
	pthread_create(&id_dec,NULL,decThread,NULL);
	pthread_join(id_inc,NULL);
	pthread_join(id_dec,NULL);
	pthread_mutex_destroy(&countmutex );     //destroy mutex
	return 0;
}
	
	

