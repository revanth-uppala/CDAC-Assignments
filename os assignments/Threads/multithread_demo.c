#include<stdio.h>
#include<pthread.h>
void* thread1(void * data)
{
    char *p = data;
    printf("Thread 1 message = %s\n",p);
}
void *thread2(void *data)
{
    char *p = data;
    printf("Thread 2 message = %s\n",p);
}
int main(int argc, char  *argv[])
{
    pthread_t tid1,tid2;
    void *arg1 = argv[1];
    void *arg2 = argv[2];
    pthread_create(&tid1,NULL,thread1,arg1);
    pthread_create(&tid2,NULL,thread2,arg2);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}

