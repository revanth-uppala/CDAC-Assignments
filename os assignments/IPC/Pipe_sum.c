#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include<stdlib.h>
#define BUFFSIZE 2
int main(int argc,char *argv[])
{
  int fd1[2],fd2[2],read_ret,write_ret,pipe1_ret,pipe2_ret;
  char buff[BUFFSIZE];
  pid_t id;

  pipe1_ret = pipe(fd1);  //parent to child
  if(pipe1_ret == -1)
  {
    perror("Pipe1:");
    exit(EXIT_FAILURE);
  }
  pipe2_ret = pipe(fd2);  //child to parent
  if(pipe2_ret == -1)
  {
    perror("Pipe2:");
    exit(EXIT_FAILURE);
  }
  id = fork();
  if(id == -1)
  {
    perror("Fork:");
    exit(EXIT_FAILURE);
  }
   if(id == 0)
  {

    close(fd1[1]); //close write end
    read_ret = read(fd1[0],buff,BUFFSIZE);


    buff[0] += buff[1];
    //printf("Sum = %d\n",(buff[0] - 96));
    close(fd1[0]); //close read end
     //write back to parent
    close(fd2[0]); //close read end
    write_ret = write(fd2[1],buff, BUFFSIZE);
    if(write_ret == -1)
    {
      perror("Writing from parent to child error:");
    }
    exit(EXIT_SUCCESS);

  }
  else
  {
    //parent
    close(fd1[0]);  //close read end
    buff[0] = atoi(argv[1]);
    buff[1] = atoi(argv[2]);

    write(fd1[1],buff,BUFFSIZE);
    printf("Sent numbers to child\n");
    close(fd1[1]);
    wait(NULL); //wait for child

    //Read sum from child
    close(fd2[1]); //close write end
    read_ret = read(fd2[0],buff,BUFFSIZE);
    printf("Sum = %d\n",buff[0]);
    exit(EXIT_SUCCESS);

  }

}
