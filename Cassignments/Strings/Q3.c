#include<stdio.h>
#include<string.h>
int main()
{
	char str[5][30];
	int i;
	int j,n;
	char temp[30];
	printf("Enter number of strings\n");
	scanf("%d",&n);
	for(i = 0;i < n ; i ++)
	{
		printf("Enter string %d :",i);
		scanf("%s",str[i]);
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - (i+1) ; j ++)
		{
			if((strcmp(str[j],str[j+1]) > 0))
			{
				strcpy(temp ,str[j]);
				strcpy(str[j] , str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	printf("After sorting the strings are:\n");	
		
	for(i = 0; i < n; i ++)
	{
		printf("String %d : ",i); 		
		printf("%s",str[i]);
		printf("\n");
	}
	return 0;
}	
			
	
