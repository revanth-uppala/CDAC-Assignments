#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#define COMMAND_LENGTH 50
#define COMMANDS 8
#define DELIMS 2
int command_search(char*);
void command_process(int);
//char *getcwd(char *buf,size_t size);
void printhelp();
void printhelp()
{
	printf("\t\tCDAC_Shell v1.0\n\t\t~Commands List~\n");
	printf("pwd\nls\ncd\nmkdir\nclear\ntree\nhelp\nexit");
}
void pwd()
{
	char *buf;
	buf = getcwd(buf,100);
	printf("%s",buf);
}
void ls()
{
	struct dirent *de;
	DIR *dr = opendir(".");
	if(dr == NULL)
	{
		printf("Could not open current directory");
		return;
	}
	while((de = readdir(dr)) != NULL)
	{
		printf(" %s\n",de->d_name);
	}
	closedir(dr);
	return;
}
void clear()
{
	system("clear");
	return;
}
	
int command_search(char *str)
{
	char command_list[COMMANDS][COMMAND_LENGTH] = {"pwd","ls","cd","mkdir","clear","tree","help","exit"};
	int i;
	for(i = 0 ; i < COMMANDS ; i ++)
	{
		if(strcmp(str,command_list[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}
void makedir()
{
	mkdir("./new",0700);
	return;
}
void command_process(int i)
{
	switch(i+1)
	{
		case 1: pwd();
			break;
		case 2: ls();
			break;
		case 3: //cd();
			break;
		case 4: makedir();
			break;
		case 5: clear();
			break;
		case 6: //tree();
			break;
		case 7: printhelp();
			break;		
		case COMMANDS: exit(1);
			break;
	}

}

int main()
{
	int command_flag = 0,i = 0,j;	
	char *str,*temp,*command_token[10];
	for(j = 0 ; j < 10 ; j ++)
	{
		command_token[j] = (char*)malloc(sizeof(char));
	} 
	char *delim = " ";
	str = (char*)malloc(sizeof(char)*COMMAND_LENGTH);
	printf("\t\tCDAC_Shell v1.0 Beta\n");
	while(1)
	{
		printf(">>");
		scanf("%s",str);
		temp = strtok(str,delim);
		command_token[0] = temp;
		i++;
		while(temp != NULL)
		{
			temp = strtok(NULL,delim);
			command_token[i++] = temp;
		}	
		command_flag = command_search(command_token[0]);
		if(command_flag == -1)
		{
			printf("\n Command %s not found\n",str);
		}
		else
		{
			command_process(command_flag);
		}
		printf("\n");
	}
	return 0;
}
