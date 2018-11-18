#include<stdio.h>

char *itoa(int n)
{	
	char str[30];
	int i;	
	while(n != 0)
	{
		str[i] = n % 10;
		n = n / 10;		
		i ++ ; 
		
	}
	printf("%s",str);
	//return p;
}
int main()
{
	int n,i;
	char *q;
	printf("Enter any number\n");
	scanf("%d",&n);
	q = itoa(n);
	printf("The number in string format is :");
	/*for(i = 0; *(q + i) != '\0' ; i ++)
	{
		printf("%c",*(q + i));
	}*/
	return 0;
}


