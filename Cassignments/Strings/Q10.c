#include<stdio.h>
void expand(char s1[],char s2[])
{
	int i,j = 0,k;
	for(i = 0 ; s1[i] != '\0' ; i ++)
	{
		if(s1[i] == 45)
		{
		
			for(k = s1[i - 1] + 1 ; k <s1[i + 1] ; k ++)
			{
				s2[j] = k;
				j ++;
			}
		}
		else
		{
			s2[j] = s1[i];
			j++;
		}
		
	}
	s2[j]='\0';
	printf("s1 is \n");
	puts(s1);
	printf("s2 is \n");
	puts(s2);
}
				 
int main()
{
	char s2[60];	
	char s1[30];
	printf("Enter a string\n");
	scanf("%s",s1);
	expand(s1,s2);
	return 0;
}
