#include<stdio.h>
#include<pthread.h>
int count;
void *incthread(void * data)
{
    while(1)
    {
        count++;
        printf("incthread: count = %d\n",count);
    }
}   
void *decthread(void *data)
{
    {
        count--;
        printf("decthread: count = %d\n",count);
    }
}
int main(int argc, char const *argv[])
{
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,incthread,NULL);
    pthread_create(&tid2,NULL,decthread,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
