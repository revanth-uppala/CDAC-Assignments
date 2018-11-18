#include<stdio.h>
#include<string.h>
void delete(char* s1,char ch)
{
    int i,temp;
    temp = 0;
    
    for(i=0;i<strlen(s1);i++)
    {
	if(s1[i]==ch)
        { 
          temp=i;
	 while(s1[i]!='\0')
          { 
	    s1[i]=s1[i+1];
	    i ++;
	    	
	  }
       	  i=temp-1;
        }
     }
   printf("string after deleting each character that matches with %c is %s\n",ch,s1);
}
int main()
{
	char s1[20];
        char c;
        printf("enter a string\n");
	 gets(s1);	
	//scanf("%[^\n]s",s1);
	printf("enter a character\n");
	scanf("%c",&c);
	//printf("%d",c);
	delete(s1,c);
	return 0;
}
