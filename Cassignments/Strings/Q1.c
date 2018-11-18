#include<stdio.h>
#include<string.h>
char* convert(char s1[])
{
   	int i;
	if(s1[0]>=65 && s1[0]<=90)
	{
	 for(i=0;i<strlen(s1);i++)
          {
		if(s1[i] == ' ')
		{
			continue;
		}	    
		s1[i]=s1[i]-'A'+'a';
		
          }
        }
        else if(s1[0]>=97 && s1[0]<=122)
         {
             for(i=0;i<strlen(s1);i++)
          {
		if(s1[i] == ' ')
		{
			continue;
		}	    
		s1[i]=s1[i]-'a'+'A';
		
          }
         }
        
       return s1;
}
int main()
{
   char s1[20];
   printf("enter a string in lower case or in upper case\n");
   scanf("%[^\n]s",s1);
   printf("Entered string is %s\n",s1);
   printf("string after converting is %s\n",convert(s1));
   return 0;
 }
