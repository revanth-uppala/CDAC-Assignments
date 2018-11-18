#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("Enter number of strings\n");
	scanf("%d",&n);
	char *str[20];
	for(i = 0; i < n; i ++)
	{
		str[i] = malloc(sizeof(char)*20);		
		printf("\nEnter string %d : ",i);
		scanf("%s",str[i]);
	}
	for(i = 0; i < n ; i ++)
	{
		printf("\nString %d : ",i);
		printf("%s",str[i]);
	}
	printf("\n");
	return 0;
}
	
