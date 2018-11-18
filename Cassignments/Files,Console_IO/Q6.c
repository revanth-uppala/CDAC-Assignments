#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void convert(char s1[])
{
   int i;
	if(s1[0]>=65 && s1[0]<=90)
	{
	 for(i=0;i<strlen(s1);i++)
          {
	    s1[i]=s1[i]-'A'+'a';
          }
        }
        else if(s1[0]>=97 && s1[0]<=122)
         {
             for(i=0;i<strlen(s1);i++)
          {
	    s1[i]=s1[i]-'a'+'A';
          }
         }
        else
         {
          printf("enter only alphabets\n");
          
         }
      
}
int main()
{
		int i;
   		char s1[20];
		char s;
   		printf("enter a string in lower case or in upper case\n");
   		scanf("%[^\n]s",s1);
		printf("Entered string is %s\n",s1);   		
		convert(s1);
   		FILE *fp;
   		fp=fopen("strfile.txt","w+");
              	if(fp == NULL)
		printf("error in opening the file");
		else
		{
		for(i=0;s1[i] != '\0';i++)
		{
			printf("%c",s1[i]);
			fputc(s1[i],fp);
		}
		}
		printf("current file position is %ld\n",ftell(fp));
		fseek(fp,0,0);
		s=fgetc(fp);
		printf("string in opposite case is\n");
		while(s != EOF)
		{
			printf("%c",s);
			s=fgetc(fp);
		}
		printf("\n");
		fclose(fp);
	return 0;
}

		
        
   
 




