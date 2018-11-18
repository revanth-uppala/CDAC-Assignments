#include<stdio.h>
#include <pthread.h>
void *thread(void *data)
{
  printf("Inside thread\n");
}
int main()
{
  pthread_t tid;
  printf("Creating thread\n");
  pthread_create(&tid,NULL,thread,NULL);
  printf("Thread created\n");
  pthread_join(tid,NULL);
}
