#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t sig1,sig2;
int a,b,add;
void *input(void *data)
{
	while(1)
	{
		sem_wait(&sig2);
		scanf("%d %d",&a,&b);
		sem_post(&sig1);
	}
}

void *output(void *data)
{
	while(1)
	{
		sem_wait(&sig1);
		add=a+b;
		printf("sum is %d\n",add);
		sem_post(&sig2);
	}
}

int main()
{
	pthread_t thread1,thread2;
	sem_init(&sig1,0,0);
	sem_init(&sig2,0,1);
	pthread_create(&thread1,NULL,input,NULL);
	pthread_create(&thread2,NULL,output,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	sem_destroy(&sig1);
	sem_destroy(&sig2);
	return 0;
}
