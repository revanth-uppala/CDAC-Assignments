///usr/share/dict/american-english
#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include <signal.h>
#include <sys/wait.h>


#define BUFFSIZE 20
static unsigned get_file_size(const char *file_name);
void strrev1( char *str);

int main(int argc,char *argv[])
{
  int i = 0,nl,line = 1,status;
  int len = strlen(argv[1]);

  char temp[1],buff[BUFFSIZE];

  pid_t id1,id2,idt;

  id1 = fork();
	if(-1 == id1)
	{
		perror("Fork1:");
		exit(EXIT_FAILURE);
	}
	if(id1 == 0)
	{
		//child1
    int open_ret;
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
					printf("'%s' found in line number %d by child1\n",argv[1],line);
					exit(EXIT_SUCCESS);
				}
				line++;
				i = 0;
			}

		}


	printf(" '%s' not found in file %s\n(child1)",argv[1],argv[2]);
  	exit(EXIT_FAILURE);
	//child1 end
	}
	else
	{
		//parent

		id2 = fork();
		if(-1 == id2)
		{
			perror("Fork2 :");
			exit(EXIT_FAILURE);
		}
		if(0 == id2)
		{
			//child2
      int open_ret;
      open_ret = open(argv[2],O_RDONLY);
  			if(open_ret == -1)
  			{
    				perror("Open file error:");
    				exit(EXIT_FAILURE);
  			}
			int bytes_read = 0;
			unsigned size;
			lseek(open_ret,0,SEEK_END); //fp to end of file
			size = get_file_size(argv[2]);
			while(bytes_read < size )
			{
				//printf("buff = %s\n",buff);
				read(open_ret,temp,1);
				if(temp[0] == EOF)
				{

					continue;
				}
				if(temp[0] != '\n')
				{
					buff[i++] = temp[0];
				}
				else
				{

					buff[i] = '\0';
					strrev1(buff);
					if(strcmp(buff,argv[1]) == 0)
					{
						printf("'%s' found in line number %d by child2\n",argv[1],99172 - line);
						exit(EXIT_SUCCESS);
					}
					line++;
					i = 0;
				}
				bytes_read ++;
        lseek(open_ret,-2,SEEK_CUR);
			 }
			printf(" '%s' not found in file %s(child2)\n",argv[1],argv[2]);
  			exit(EXIT_FAILURE);
			//child2 end
		}
		idt = wait(&status);
		if(idt == id1)
		{
			if(kill(id2,SIGKILL) == -1)
			{
				perror("Kill id2 error");
			}

		}
		else
		{
			if(kill(id1,SIGKILL) == -1)
			{
				perror("Kill id1 error");
			}
		}


		exit(0);
	}
	return 0;
}
static unsigned get_file_size(const char *file_name)
{
	struct stat sb;
	if(stat(file_name, &sb) != 0)
	{
			perror("Stat fail:");
			exit(EXIT_FAILURE);
	}
	return sb.st_size;
}
void strrev1( char *str)
{
	int i,l;
	l = strlen(str);
	for(i = 0; i < (l/2) ; i ++ )
	{
		char temp;
		temp = str[i];
		str[i] = str[l- (i+1)];
		str[l - (i+ 1)] = temp;
	}

}
