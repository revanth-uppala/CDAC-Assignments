//#include<stdio.h>
char* strcpy1(char *str1,char *str2)
{
	int i;
	char *q;	
	for(i = 0; str2[i] != '\0' ; i++)
	{
		str1[i] = str2[i];
	}
	q = str1;
	return q;
	

}
/*int main()
{
	char str1[20],str2[20],*p;
	printf("Enter first string\n");
	scanf("%s",str1);
	printf("Enter second string\n");
	scanf("%s",str2);
	
	printf("Before copying\nString 1: %s\nString 2: %s\n",str1,str2);
	p = strcpy1(str1,str2);
	printf("After copying\nString 1: %s\nString 2: %s\n",p,str2);
	return 0;
}*/
