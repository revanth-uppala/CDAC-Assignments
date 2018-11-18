///usr/share/dict/american-english
#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#define BUFFSIZE 20
int main(int argc,char *argv[])
{
  int i = 0,line = 1;
  int len = strlen(argv[1]);
  char buff[BUFFSIZE],temp[1];
  int open_ret,read_ret;
  open_ret = open(argv[2],O_RDONLY);
  if(open_ret == -1)
  {
    perror("Open file error:");
    exit(EXIT_FAILURE);
  }

    while(read(open_ret,temp,1) > 0)
		{
			//printf("buff = %s\n",buff);
			if(temp[0] != '\n')
			{
				buff[i++] = temp[0];
			}
			else
			{
				buff[i] = '\0';
				if(strcmp(buff,argv[1]) == 0)
				{
					printf("'%s' found in line number %d \n",argv[1],line);
					exit(EXIT_SUCCESS);
				}
				line++;
				i = 0;
			}

		}


	printf(" '%s' not found in file %s\n",argv[1],argv[2]);
  	exit(EXIT_FAILURE);

}
