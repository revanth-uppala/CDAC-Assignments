#include <stdio.h>
#include <pthread.h>
int count;
void *incThread(void *data)
{
	while(1)
	{
		count++;
		printf("incthread: %d\n",count);
	}
	
}
void *decThread(void *data)
{
	while(1)
	{
		count--;
		printf("decthread: %d\n",count);
	}
	
}
int main()
{
	pthread_t id_inc,id_dec;
	pthread_create(&id_inc,NULL,incThread,NULL);
	pthread_create(&id_dec,NULL,decThread,NULL);
	pthread_join(id_inc,NULL);
	pthread_join(id_dec,NULL);
	return 0;
}
	
	

