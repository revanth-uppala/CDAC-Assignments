//#include<stdio.h>
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
/*int main()
{
	char str[20];
	printf("Enter any string\n");
	scanf("%s",str);
	printf("Entered string is %s\n",str);
	strrev1(str);
	printf("Reversed string is %s\n",str);
	return 0;
}*/
