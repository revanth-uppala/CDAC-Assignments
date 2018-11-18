#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char *argv[])
{
	pid_t id;
	int ret;
	char buff[30];
	int i=0;
	int status;
	float cpi,fpc,tpc;
	printf("Enter cycles per instruction:\n");
	scanf("%f",&cpi);
	printf("Enter CPU frequency in MHz\n");
	scanf("%f",&fpc);
	tpc = (1/fpc);
 	 
	char *str[2];
	for(i = 0 ; i < 2 ; i ++)
	{
		str[i] = (char*)malloc(sizeof(char)*20);
	}
	str[0] = strcpy(str[0],"-S -o target ");
	strcat(str[0],argv[1]);
	str[1] = NULL;
	char str2[]="gcc";
	
	
	id=fork();
	if(-1 == id)
	{
		perror("FORK:");
		exit(0);
	}
	else if(0 == id)
	{
		ret=execvp(str2,str);
		if(-1 == ret)
		{
			perror("EXEC:");
		}
		exit(EXIT_SUCCESS);
		
	}
	else
	{
		int count=0;
		float ex_time=0;
		ret=wait(&status);
		FILE *fp;
		fp=fopen("target","r");
		if(fp== NULL)
		{
			printf("error in opening file\n");
		}
		else
		{
			char c=fgetc(fp);
			while(c != EOF)
			{
							
				if(c == '.')
				{
					while(c != '\n')
					{
						c=fgetc(fp);
					}
					c=fgetc(fp);
					

				}
				else
				{
					while(c != '\n')
					{
						buff[i++]=c;
						c=fgetc(fp);
					}
					
					if(strcmp(buff,"main:") == 0)
					{
						
					}
					else	
					{
						count++;
					}
					c=fgetc(fp);
				}
			}
			ex_time = count * cpi * tpc;
			printf("Approximate xecution time of %s = %f\n",argv[1],ex_time);
			exit(0);
		}  
	}
	return 0;
}
			
