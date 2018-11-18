#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int a,b,add;
void *input(void *data)
{
	while(1)
	{
		
		scanf("%d %d",&a,&b);
		
	}
}

void *output(void *data)
{
	while(1)
	{
		add=a+b;
		printf("sum is %d\n",add);
	}
}

int main()
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,input,NULL);
	pthread_create(&thread2,NULL,output,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
