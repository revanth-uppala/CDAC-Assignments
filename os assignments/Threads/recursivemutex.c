#include<stdio.h>
#include<pthread.h>
int count;
pthread_mutex_t countMutex;
void *incthread(void * data)
{
    while(1)
    {
        pthread_mutex_lock(&countMutex);
         pthread_mutex_lock(&countMutex);
        count++;
        printf("incthread: count = %d\n",count);
        pthread_mutex_unlock(&countMutex);
        pthread_mutex_unlock(&countMutex);

    }
}   
void *decthread(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&countMutex);
        pthread_mutex_lock(&countMutex);
        count--;
        printf("decthread: count = %d\n",count);
        pthread_mutex_unlock(&countMutex);
        pthread_mutex_unlock(&countMutex);
    }
}
int main(int argc, char const *argv[])
{
    pthread_t tid1,tid2;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init (&attr);
    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&countMutex,&attr);
    pthread_create(&tid1,NULL,incthread,NULL);
    pthread_create(&tid2,NULL,decthread,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_mutexattr_destroy(&attr);
    pthread_mutex_destroy(&countMutex);
    return 0;
}
