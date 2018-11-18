#include<string.h>
void strrev1(char *str)
{
	char temp;
	int i = 0,j = strlen(str) - 1;
	for(i = 0,j = strlen(str) - 1; i <= j; i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	   
	
		
}

char* strcpy1(char *str1,char *str2)
{
	int i;
	char *q;	
	for(i = 0; str2[i] != '\0' ; i++)
	{
		str1[i] = str2[i];
	}
	str1[i] = '\0'; 	
	q = str1;
	return q;
	

}
char* strcat1(char *str1,char *str2)
{
	int i = 0,j,count = 0;
	char *q;	
	while(str1[i]!='\0')
	{
            count++;
	    i++;
	}
	//str1[i] = '+';
	for(i = count,j = 0 ; str2[j] != '\0';i ++,j++)
	{
		str1[i] = str2[j];
	}
	str1[i] = '\0';
	q = str1;
	return q;
}
int strcmp1(char *str1,char *str2)
{
	int i,j;
	for(i=0,j=0;i<strlen(str1),j<strlen(str2);i++,j++)
	{
		if(str1[i] == str2[j])
		{
						
			continue;
		}
		else if(str1[i] > str2[j])
		{
			return 1;
		}
		else if(str1[i] < str2[j])
		{
			return -1;
		}
	}
	return 0;
}
		


