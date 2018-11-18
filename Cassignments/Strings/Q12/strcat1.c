#include<stdio.h>
//#include<string.h>
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
	
	q = str1;
	return q;
	

}
/*int main()
{
	char str1[40],str2[20],*p;
	printf("Enter first string\n");
	scanf("%s",str1);
	printf("Enter second string\n");
	scanf("%s",str2);
	
	printf("\nBefore concatenation : \nString 1: %s\nString 2: %s\n",str1,str2);
	p = strcat1(str1,str2);
	printf("After concatenation\nString 1: %s\nString 2: %s\n",p,str2);
	return 0;
}*/
