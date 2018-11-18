#include<stdio.h>
#include<string.h>
void deletes(char s1[],char s2[])
{
     int i,j,temp;
     for(i=0;i<strlen(s1);i++)
     {
     for(j=0;j<strlen(s2);j++)
     {
	if(s1[i]==s2[j])
        {
         temp=i;
         while(s1[i] != '\0')
         {
	 s1[i]=s1[i+1];
	 i++;
	 }
       i=temp;
       j=-1;
     }
     }
     }
       printf("s1 after changes is %s\n",s1);
}
int main()
{
char s1[20],s2[20];
printf("enter string s1\n");
scanf("%s",s1);
printf("enter string s2\n");
scanf("%s",s2);
deletes(s1,s2);
return 0;
}		 
    
