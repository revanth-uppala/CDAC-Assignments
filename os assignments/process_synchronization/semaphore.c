#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int s=1;
int a,b,add;
void wait()
{
	while(s<=0);
	s=0;
}
void post()
{
	s=1;
}
void *input(void *data)
{
	while(1)
	{
		wait();
		scanf("%d %d",&a,&b);
		post();
	}
	
}

void *output(void *data)
{
	
	
	while(1)
	{
		wait();
		add=a+b;
		printf("sum is %d\n",add);
		post();
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

