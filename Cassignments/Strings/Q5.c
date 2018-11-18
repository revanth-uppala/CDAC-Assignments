#include<stdio.h>
#include<string.h>
int calc(char s1[],char s2[])
{
	int i,j,temp;
    for(i=0;i<strlen(s1);i++)
    {
    for(j=0;j<strlen(s2);j++)
    {
       if(s1[i]==s2[j])
        {
	 return i;
	}
    }
    }
	return -1;
  
}
int main()
{
int temp;
char s1[20],s2[20];
printf("enter string 1\n");
gets(s1);
printf("entr string 2\n");
gets(s2);
temp=calc(s1,s2);
if(temp > 0)

	printf("the first location in the string s1 which matches with any string in s2 is s1[%d]\n",temp);
else
	printf("No match found\n");
return 0;
}
